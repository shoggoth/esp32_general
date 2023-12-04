#include "Plus.hpp"
#include <iostream>
#include <string>

class Foo {
};

void setup() {
  // put your setup code here, to run once:
  auto lambda = [](std::string s) { std::cout << "Lambdad " << s << std::endl; };

  for (int foo = 0;; foo++) {
    printf("Foo is %d\n", foo);
    lambda("Hoo boy!");
    for (int bar = 0; bar < 3; bar++) {
      printf("3 bars nagged %d, %d\n", foo, bar);
      tradFunc("Niggers gonna nig trad style");
      plusFunc("They gonna nig as well in a new style");
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
