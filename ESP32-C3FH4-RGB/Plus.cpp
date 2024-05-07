#include <iostream>
#include <thread>
#include "Plus.hpp"

void threadMessing() {

  auto lambda = [](std::string s) { std::cout << "Threaded " << s << std::endl; };

  std::thread thread(lambda, "Noggin");

  thread.join();
}

void plusFunc(std::string str) {
  std::cout << "Plus string is " << str << std::endl;
}

static void niggerTemp() {

  for (int foo = 0; foo < 3; foo++) {
    printf("Foo is %d\n", foo);
    for (int bar = 0; bar < 3; bar++) {
      printf("3 bars nagged %d, %d\n", foo, bar);
      tradFunc("Niggers gonna nig trad style");
      plusFunc("They gonna nig as well in a new style");
    }
  }
}