#include "Plus.hpp"
#include "NeoPixRenderer.hpp"
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
static std::unique_ptr<std::thread> thread_ptr_3;

class Foo {
};

static std::unique_ptr<NeoPixRenderer> renderer = std::unique_ptr<NeoPixRenderer>(new NeoPixRenderer());
const short led_pin = 10;  // Status LED (blue)

void setup() {
  // put your setup code here, to run once:
  //delay(1000);

  thread_ptr_1 = std::unique_ptr<std::thread>(new std::thread(tlam, "One"));
  thread_ptr_2 = std::unique_ptr<std::thread>(new std::thread(tlam, "Two"));
  thread_ptr_3 = std::unique_ptr<std::thread>(new std::thread([] { for (;;) { renderer->render(); delay(100); }}));
  
  threadMessing();
  thread_ptr_1->detach();
  thread_ptr_2->detach();
  thread_ptr_3->detach();
  
  //[](std::string s) { std::cout << "Anon lambda " << s << std::endl; } ("Hoo boy!");

  //renderer->render();

  pinMode(led_pin, OUTPUT);
}

static int pixel = 0;

void loop() {
  // put your main code here, to run repeatedly:
  //std::cout << "Going round the main loop: " << std::endl;

  //renderer->render();
  digitalWrite(led_pin, HIGH);
  delay(100);

  digitalWrite(led_pin, LOW);
  delay(100);
}
