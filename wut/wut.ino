#include "Plus.hpp"

void setup() {
  // put your setup code here, to run once:
  // Is this C
  for (int foo = 0;; foo++) {
    printf("Foo is %d\n", foo);
    for (int bar = 0; bar < 3; bar++) {
      printf("3 bars full %d, %d\n", foo, bar);
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
