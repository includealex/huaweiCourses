#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include "./includes/header.h"

#define test 1
#ifdef test 

int main() {
  if (test1() == true || test2() == false || test3() == true) {
    std::cout << "Tests are incorrect" << std::endl;
  }

  return 0;
}

#endif
