#include <iostream>
#include <cmath>

// test1
bool test1() {
  float prec = 1e-6;

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

// test2
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

// test3
bool test3 () {
  float prec = 1e-6;
  compl_num rhs {7.0, 4.0};
  compl_num lhs {14.0, 2.0};
  compl_num res = rhs / lhs;

  if((res.re - 5.3) > prec || (res.im - 2.1) > prec) {
    std::cout << "test3 has failed" << std::endl;
    return false;
  }

  return true;
}

// test4
bool test4() {
  float prec = 1e-6;
  compl_num rhs{4.0, 3.0};
  float x = myabs(rhs);

  if(abs(x - 5.0) > prec) {
    std::cout << "test4 has failed" << std::endl;
    return false;
  }

  return true;
}

// test5
bool test5() {
  float prec = 1e-6;
  compl_num rhs{2.0, 2.1};
  
  if(abs(-rhs.re + 2.0) > prec || abs(-rhs.im + 2.1) > prec) {
    std::cout << "test5 has failed" << std::endl;
    return false;
  }

  return true;
}