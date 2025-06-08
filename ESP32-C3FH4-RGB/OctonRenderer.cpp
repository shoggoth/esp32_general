#include "OctonRenderer.hpp"
#include <iostream>

OctonRenderer::OctonRenderer(const uint8_t brightness) {
  strip = Adafruit_NeoPixel(num_leds, led_pin, NEO_GRB + NEO_KHZ800);
  strip.begin();
  setBrightness(brightness);
}

void OctonRenderer::render(uint16_t octon, uint8_t intensity) {
  int r = rand() % intensity, g = rand() % intensity, b = rand() % intensity;
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

void OctonRenderer::renderByteValue(const uint8_t value) {
  strip.clear();
  int mask = 1;
  for (int i = 0; i < 8; i++) {
    if (value & mask) strip.setPixelColor(i, 255, 255, 255);
    mask = mask << 1;
  }
  strip.show();
}

void OctonRenderer::setBrightness(const uint8_t brightness) { strip.setBrightness(brightness); }