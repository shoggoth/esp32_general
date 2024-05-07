#include "Plus.hpp"
#include "NeoPixRenderer.hpp"
#include <iostream>
#include <string>
#include <thread>

static auto tlam = [](std::string s) {
  for (;;) {
    std::cout << "Thread ID: " << std::this_thread::get_id() << " - " << s << std::endl;
    delay(3000);
    }
  };
  
static std::unique_ptr<std::thread> phys_thread;
static std::unique_ptr<std::thread> sync_thread;
static std::unique_ptr<std::thread> draw_thread;

static std::unique_ptr<NeoPixRenderer> renderer = std::unique_ptr<NeoPixRenderer>(new NeoPixRenderer());
const short button_pin = 9; // Button
const short led_pin = 10;   // Status LED (blue)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  phys_thread = std::unique_ptr<std::thread>(new std::thread(tlam, "TODO: Physics"));
  sync_thread = std::unique_ptr<std::thread>(new std::thread(tlam, "TODO: Sync"));
  draw_thread = std::unique_ptr<std::thread>(new std::thread([] { for (;;) { renderer->render(); delay(16); }}));
  
  phys_thread->detach();
  sync_thread->detach();
  draw_thread->detach();
 
  pinMode(led_pin, OUTPUT);
  pinMode(button_pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) std::cout << "From serial: " << (char)Serial.read() << std::endl;
  
  static unsigned button_value = 1;
  static unsigned mark_space = 0;
  unsigned v = digitalRead(button_pin);
  if (v != button_value) {
    mark_space = button_value ? 500 : rand() % 480;
    button_value = v;
  }

  digitalWrite(led_pin, HIGH);
  delay(500 + mark_space);
  digitalWrite(led_pin, LOW);
  delay(500 - mark_space);
}
