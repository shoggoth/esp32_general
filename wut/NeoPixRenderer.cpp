#include "NeoPixRenderer.hpp"
#include <iostream>

NeoPixRenderer::NeoPixRenderer(const uint8_t v, const uint32_t ma) {
  std::cout << "Constructin" << std::endl;
  strip = Adafruit_NeoPixel(num_leds, led_pin, NEO_GRB + NEO_KHZ800);
  strip.clear();
  strip.show();
}

void NeoPixRenderer::render() {
  std::cout << "Rendering" << std::endl;
  strip.show();
}
