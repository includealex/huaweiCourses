#include <cstddef>

//test +
bool test1() {
  compl_num rhs {4.1, 5.2};
  compl_num lhs {4.2, 5.1};
  compl_num result = rhs  + lhs;

  if (result.re != 8.3 || result.im != 10.3) 
    return false;

  return true;
}

//test *
bool test2() {
  srand(time(NULL));

  compl_num rhs{0.0, 0.0};
  compl_num lhs{0.0, 0.0};
  compl_num res{0.0, 0.0};

  for (int i = 0; i < 1000; ++i) {
    lhs.re = rand()%1000 + 1 + (rand()% 1) / 10;
    lhs.im = rand()%1000 + 1 + (rand()% 1) / 10;

    res = rhs * lhs;

    if(res.re != 0.0 || res.im != 0.0) {
      return false;
    }
  }

  return true;
}

//test /

bool test3 () {
  compl_num rhs {7.0, 4.0};
  compl_num lhs {14.0, 2.0};
  compl_num res = rhs / lhs;

  if(res.re != 0.53 && res.im != 0.21) {
    return false;
  }

  return true;
}
