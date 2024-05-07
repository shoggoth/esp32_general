#include "OctonRenderer.hpp"
#include <iostream>
#include <string>
#include <thread>

static auto renderer = std::unique_ptr<OctonRenderer>(new OctonRenderer(64));

const short button_pin = 9; // Button
const short led_pin = 10;   // Status LED (blue)

static unsigned mark_space = 1000;
static auto mark_space_blink = [mark_space](short led_pin) {
  for (;;) {
    digitalWrite(led_pin, HIGH);
    delay(mark_space);
    digitalWrite(led_pin, LOW);
    delay(1000 - mark_space);
  }
};

void setup() {
  // Hardware setup
  pinMode(led_pin, OUTPUT);
  pinMode(button_pin, INPUT);

  // Threads setup
  static int t = 0;
  auto draw_thread = std::unique_ptr<std::thread>(new std::thread([] { for (;;) { renderer->render(rand() % 0x7fff); delay(1500); }}));
  auto blnk_thread = std::unique_ptr<std::thread>(new std::thread(mark_space_blink, led_pin));
  draw_thread->detach();
  blnk_thread->detach();
}

void loop() {
  if (!digitalRead(button_pin)) mark_space = rand() % 1000;
}
