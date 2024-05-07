#include "OctonRenderer.hpp"
#include <iostream>

OctonRenderer::OctonRenderer(const short brightness) {
  strip = Adafruit_NeoPixel(num_leds, led_pin, NEO_GRB + NEO_KHZ800);
  strip.begin();
  strip.setBrightness(brightness);
}

void OctonRenderer::render(uint16_t octon) {
  int r = rand() % 64, g = rand() % 64, b = rand() % 64;
  strip.clear();
  for (int i = 0; i < 15; i++) {
    if (octon & 1) {
      int x = i % 3, y = (i / 3) * 5;
      strip.setPixelColor(x + y, r, g, b);
      if (x < 2) strip.setPixelColor((4 - x) + y, r, g, b);
    }
    octon = octon >> 1;
  }
  strip.show();
}
