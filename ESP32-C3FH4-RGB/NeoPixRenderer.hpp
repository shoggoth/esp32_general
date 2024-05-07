#include <Adafruit_NeoPixel.h>

class NeoPixRenderer {
  static constexpr unsigned num_leds = 25;
  static constexpr unsigned led_pin = 8;

  Adafruit_NeoPixel strip;
  
public:
  NeoPixRenderer(const uint8_t v = 5, const uint32_t ma = 4000);
  void render();
};