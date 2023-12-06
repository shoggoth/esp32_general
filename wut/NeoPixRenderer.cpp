#include "NeoPixRenderer.hpp"
#include <iostream>

NeoPixRenderer::NeoPixRenderer(const uint8_t v, const uint32_t ma) {
  std::cout << "Constructin" << std::endl;
  strip = Adafruit_NeoPixel(num_leds, led_pin, NEO_GRB + NEO_KHZ800);
  strip.begin();
  strip.clear();
}

void NeoPixRenderer::render() {
  std::cout << "Rendering" << std::endl;
  strip.clear();
  strip.setPixelColor(rand() % num_leds, rand() % 255, 0, 0);
  strip.show();
}
