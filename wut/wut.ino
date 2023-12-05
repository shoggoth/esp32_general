#include "Plus.hpp"
#include "FastLEDRenderer.hpp"
#include <iostream>
#include <string>
#include <thread>

static auto tlam = [](std::string s) {
  for (;;) {
    std::cout << "Thread ID: " << std::this_thread::get_id() << " - " << s << std::endl;
    delay(777);
    }
  };
static std::unique_ptr<std::thread> thread_ptr_1;
static std::unique_ptr<std::thread> thread_ptr_2;

class Foo {
};

static std::unique_ptr<FastLEDRenderer> renderer = std::unique_ptr<FastLEDRenderer>(new FastLEDRenderer());
const short led_pin = 10;  // Status LED (blue)

void setup() {
  // put your setup code here, to run once:
  delay(1000);

  thread_ptr_1 = std::unique_ptr<std::thread>(new std::thread(tlam, "One"));
  thread_ptr_2 = std::unique_ptr<std::thread>(new std::thread(tlam, "Two"));
  threadMessing();
  
  [](std::string s) { std::cout << "Anon lambda " << s << std::endl; } ("Hoo boy!");

  pinMode(led_pin, OUTPUT);
}

static int pixel = 0;

void loop() {
  // put your main code here, to run repeatedly:
  std::cout << "Going round the main loop: " << std::endl;

  renderer->render();
  digitalWrite(led_pin, HIGH);
  delay(100);

  digitalWrite(led_pin, LOW);
  delay(100);
}
