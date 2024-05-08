#include "OctonRenderer.hpp"
#include <iostream>
#include <string>
#include <thread>

static uint8_t brightness = 32;
static unsigned mark_space = brightness * 4;
static auto renderer = std::unique_ptr<OctonRenderer>(new OctonRenderer(brightness));

const short button_pin = 9; // Button
const short led_pin = 10;   // Status LED (blue)

static auto mark_space_blink = [mark_space](short led_pin) {
  for (;;) {
    digitalWrite(led_pin, HIGH);
    delay(mark_space);
    digitalWrite(led_pin, LOW);
    delay(1024 - mark_space);
  }
};

void setup() {
  // Hardware setup
  pinMode(led_pin, OUTPUT);
  pinMode(button_pin, INPUT);

  // Threads setup
  static int t = 0;
  auto draw_thread = std::unique_ptr<std::thread>(new std::thread([] { for (;;) { renderer->render(rand() % 0x7fff); delay(2048); }}));
  auto blnk_thread = std::unique_ptr<std::thread>(new std::thread(mark_space_blink, led_pin));
  draw_thread->detach();
  blnk_thread->detach();
}

void loop() {
  static bool was_pressed = false;
  bool now_pressed = !digitalRead(button_pin);
  if (now_pressed != was_pressed) {
    was_pressed = now_pressed;
    if (now_pressed) {
      brightness = (brightness >> 1 | brightness << 7);
      mark_space = brightness * 4;
      renderer->setBrightness(brightness);
      renderer->renderByteValue(brightness);
    }
  }
}
