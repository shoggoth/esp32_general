#define FASTLED_INTERNAL
#include <FastLED.h>

class FastLEDRenderer {
  static constexpr int num_leds = 25;
  static constexpr int led_pin = 8;

  CRGBArray<num_leds> leds;
  
public:
  FastLEDRenderer(const uint8_t v = 5, const uint32_t ma = 4000);
  void render();
};