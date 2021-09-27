#include <iostream>
#include <cmath>
#include "../includes/test_header.hpp"

#define prec 1e-6

bool test1() {
  compl_num rhs {4.1, 5.2};
  compl_num lhs {4.2, 5.1};
  compl_num result = rhs  + lhs;

  if (abs(result.re - 8.3) > prec || abs(result.im - 10.3) > prec) {
    std::cout << "test1.1 has failed" << std::endl;
    return false;
  }

  result = rhs - lhs;
  if (abs(result.re + 0.1) > prec || abs(result.im - 0.1) > prec) {
    std::cout << "test1.2 has failed" << std::endl;
    return false;
  }

  return true;
}

bool test2() {
  compl_num rhs{1.0, 2.0};
  compl_num lhs{1.0, 2.0};
  float num = 7;
  compl_num res = rhs * num;


  if(res.re != 7.0 || res.im != 14.0) {
    std::cout << "test2.1 has failed" << std::endl;
    return false;
  }

  res = rhs * lhs;
  if(res.re != -3.0 || res.im != 4.0) {
    std::cout << "test2.2 has failed. res.re = " << res.re << " res.im = " << res.im << std::endl;
    return false;
  }

  return true;
}

bool test3 () {
  compl_num rhs {7.0, 4.0};
  compl_num lhs {14.0, 2.0};
  compl_num res = rhs / lhs;

  if((res.re - 5.3) > prec || (res.im - 2.1) > prec) {
    std::cout << "test3 has failed" << std::endl;
    return false;
  }

  return true;
}

bool test4() {
  compl_num rhs{4.0, 3.0};
  float x = myabs(rhs);

  if(abs(x - 5.0) > prec) {
    std::cout << "test4 has failed" << std::endl;
    return false;
  }

  return true;
}

bool test5() {
  compl_num rhs{2.0, 2.1};
  
  if(abs(-rhs.re + 2.0) > prec || abs(-rhs.im + 2.1) > prec) {
    std::cout << "test5 has failed" << std::endl;
    return false;
  }

  return true;
}

bool test6() {
  compl_num rhs {2.7, 4.9};
  compl_num lhs {0.0, 0.0};
  lhs = rhs;

  if(abs(rhs.re - lhs.re) > prec || abs(rhs.im - lhs.im) > prec) {
    std::cout << "test6 has failed" << std::endl;
    return false;
  }

  return true;
}

bool test7() {
  compl_num rhs{2.4, 7.8};
  compl_num lhs{0.0, 0.0};
  float num = 7.6;

  lhs = rhs + num;

  if(abs(lhs.re - 10) > prec) {
    std::cout << "test7.1 has failed" << std::endl;
    return false;
  }

  lhs = rhs - 2 * num;

  if(abs(lhs.re + 12.8) > prec) {
    std::cout << "test7.2 has failed" << std::endl;
    return false;
  }

  return true;
}

bool test8() {
  compl_num rhs{2.0, 7.1};
  float num = 2;
  compl_num lhs{0.0, 0.0};

  lhs = rhs * num;
  if(abs(lhs.re - 4.0) > prec || abs(lhs.im - 14.2) > prec) {
    std::cout << "test8 has failed" << std::endl;
    return false;
  }

  return true;
}

bool test9() {
  compl_num rhs{2.2, 7.4};
  float num = 2;
  compl_num lhs{0.0, 0.0};

  lhs = rhs / num;
  if(abs(lhs.re - 1.1) > prec || abs(lhs.im - 3.7) > prec) {
    std::cout << "test9 has failed" << std::endl;
    return false;
  }

  return true;
}

bool test10() {
  compl_num rhs{1.2, 3.4};
  compl_num lhs{0.5, 1.4};

  rhs += lhs;
  if(abs(rhs.re - 1.7) > prec || abs(rhs.im - 4.8) > prec) {
    std::cout << "test10.1 has failed" << std::endl;
    return false;
  }

  rhs -= lhs;
  if(abs(rhs.re - 1.2) > prec || abs(rhs.im - 3.4) > prec) {
    std::cout << "test10.2 has failed" << std::endl;
    return false;
  }

  return true;
}

bool test11 () {
  compl_num rhs {1.0, 2.0};
  compl_num lhs {4.0, 8.0};

  rhs *= lhs;
  if (abs(rhs.re + 12.0) > prec || abs(rhs.im - 16.0) > prec) {
    std::cout << "test11 has failed" << std::endl;
    return false;
  }

  return true;
}

bool test12() {
  compl_num rhs {2.0, 2.0};
  compl_num lhs {4.0, 8.0};

  rhs /= lhs;
  if (abs(rhs.re -0.3) > prec || abs(rhs.im + 0.1) > prec) {
    std::cout << "test12 has failed" << std::endl;
    return false;
  }

  return true;
}

bool test13() {
  compl_num rhs {2.3, 4.5};
  compl_num lhs {2.3, 4.5};

  if((lhs != rhs)) {
    std::cout << "test13.1 has failed" << std::endl;
    return false;
  }

  else if(lhs == rhs) {
    return true;
  }

  std::cout << "test 13.2 has failed" << std::endl;
  return false;
}

void grandTest() {
  if (test1()  == false) {std::cout << "FAILURE" << std::endl;}
  if (test2()  == false) {std::cout << "FAILURE" << std::endl;}
  if (test3()  == false) {std::cout << "FAILURE" << std::endl;}
  if (test4()  == false) {std::cout << "FAILURE" << std::endl;}
  if (test5()  == false) {std::cout << "FAILURE" << std::endl;}
  if (test6()  == false) {std::cout << "FAILURE" << std::endl;}
  if (test7()  == false) {std::cout << "FAILURE" << std::endl;}
  if (test8()  == false) {std::cout << "FAILURE" << std::endl;}
  if (test9()  == false) {std::cout << "FAILURE" << std::endl;}
  if (test10() == false) {std::cout << "FAILURE" << std::endl;}
  if (test11() == false) {std::cout << "FAILURE" << std::endl;}
  if (test12() == false) {std::cout << "FAILURE" << std::endl;}
  if (test13() == false) {std::cout << "FAILURE" << std::endl;}
}