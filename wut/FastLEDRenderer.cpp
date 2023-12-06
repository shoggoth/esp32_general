#include "FastLEDRenderer.hpp"
#include <iostream>

FastLEDRenderer::FastLEDRenderer(const uint8_t v, const uint32_t ma) {
  std::cout << "Constructin" << std::endl;
  FastLED.setMaxPowerInVoltsAndMilliamps(v, ma);
  //FastLED.addLeds<NEOPIXEL, led_pin>(leds, num_leds).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<NEOPIXEL, led_pin>(leds, num_leds);
  FastLED.clearData();
}

void FastLEDRenderer::render() {
  std::cout << "Rendering" << std::endl;
  leds[0] = CRGB(rand() % 255, 0, 0);
  FastLED.show();
}
