#include <Adafruit_NeoPixel.h>

class OctonRenderer {
  static constexpr unsigned num_leds = 25;
  static constexpr unsigned led_pin = 8;

  Adafruit_NeoPixel strip;
  
public:
  OctonRenderer(const uint8_t brightness = 255);
  
  void render(uint16_t octon, uint8_t intensity = 255);
  void renderByteValue(const uint8_t value);
  void setBrightness(const uint8_t brightness);
};