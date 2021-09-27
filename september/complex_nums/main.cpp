#include <iostream>
#include "source/funcs.cpp"
#include "TestDir/test.cpp"

int main() {
  if (test1() == true || test2() == false || test3() == true) {
    std::cout << "Tests are incorrect" << std::endl;
  }

  return 0;
}
