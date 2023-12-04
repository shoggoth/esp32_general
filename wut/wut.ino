#include "Plus.hpp"
#include <iostream>
#include <string>

class Foo {
};

const short led_pin = 10;   // Staus LED (blue)

void setup() {
  // put your setup code here, to run once:
  auto lambda = [](std::string s) { std::cout << "Lambdad " << s << std::endl; };

  for (int foo = 0; foo < 3; foo++) {
    printf("Foo is %d\n", foo);
    lambda("Hoo boy!");
    for (int bar = 0; bar < 3; bar++) {
      printf("3 bars nagged %d, %d\n", foo, bar);
      tradFunc("Niggers gonna nig trad style");
      plusFunc("They gonna nig as well in a new style");
    }
  }

  pinMode(led_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(led_pin, HIGH);
  delay(500);
  digitalWrite(led_pin, LOW);
  delay(500);
}
