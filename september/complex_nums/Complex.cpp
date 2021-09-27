#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#define test 1

struct compl_num {
  float re;
  float im;

  compl_num();
  compl_num(float new_re, float new_im);
  compl_num(const compl_num& other);

  compl_num& operator=(const compl_num &other);
  compl_num operator+(const compl_num &other) const;
  compl_num operator-(const compl_num &other) const;
  compl_num operator*(const compl_num &other) const;
  compl_num operator/(const compl_num &other) const;

  float myabs() const;
};

bool test1();
bool test2();
bool test3();

#ifdef test 

int main() {
  if (test1() ==  true || test2() == false || test3() == true) {
    printf("Tests are incorrect\n");
  }

  return 0;
}

#endif

compl_num::compl_num(float new_re, float new_im) : re(new_re), im(new_im) {} //initialisation list
compl_num::compl_num(const compl_num& other) : re(other.re), im(other.im) {}

float compl_num::myabs() const {
  return sqrt(re * re + im * im);
}

compl_num compl_num::operator+(const compl_num& other) const {
  compl_num res{re + other.re, im + other.im};
  return res;
}

compl_num compl_num::operator-(const compl_num& other) const {
  compl_num res{re - other.re, im - other.im};
  return res;
}

compl_num compl_num::operator*(const compl_num &other) const {
  compl_num res{re * other.re - im * other.im, re * other.im + im * other.re};
  return res;
}

compl_num compl_num::operator/(const compl_num &other) const {
  compl_num res{(re * other.re + im * other.im) / (im * im + other.im * other.im), (im * other.re - re * other.im) / (im * im + other.im * other.im)};
  return res;
}

compl_num& compl_num::operator=(const compl_num& other) {
  if (this != &other) {
    re = other.re;
    im = other.im;
  }

  return *this;
}

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