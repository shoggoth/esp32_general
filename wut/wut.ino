#include "Plus.hpp"
#include <iostream>
#include <string>
#include <thread>
#include <Adafruit_NeoPixel.h>

#define LED_PIN 8
Adafruit_NeoPixel strip = Adafruit_NeoPixel(25, LED_PIN, NEO_GRB + NEO_KHZ800);

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

const short led_pin = 10;  // Staus LED (blue)

void setup() {
  // put your setup code here, to run once:

  thread_ptr_1 = std::unique_ptr<std::thread>(new std::thread(tlam, "One"));
  thread_ptr_2 = std::unique_ptr<std::thread>(new std::thread(tlam, "Two"));
  threadMessing();
  
  auto lambda = [](std::string s) { std::cout << "Lambdad " << s << std::endl; };

  lambda("Hoo boy!");

  pinMode(led_pin, OUTPUT);

  strip.begin();
  strip.setBrightness(50);
  strip.show();
}

static int pixel = 0;

void loop() {
  // put your main code here, to run repeatedly:
  std::cout << "Going round the main loop: " << std::endl;

  digitalWrite(led_pin, HIGH);
  delay(100);

  digitalWrite(led_pin, LOW);
  strip.setPixelColor(pixel++ % 25, strip.Color(rand() % 255, rand() % 255, rand() % 255));
  strip.show();
  delay(100);
}
