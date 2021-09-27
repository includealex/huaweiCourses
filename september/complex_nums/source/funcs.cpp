#include "../includes/header.hpp"
#include <cmath>

compl_num::compl_num(float new_re, float new_im) : re(new_re), im(new_im) {} //initialisation list
compl_num::compl_num(const compl_num& other) : re(other.re), im(other.im) {}

float myabs(const compl_num &rhs) {
  return sqrt(rhs.re * rhs.re + rhs.im * rhs.im);
}

/*
float compl_num::myabs() {
  return sqrt(re * re + im * im);
}
*/

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

compl_num& compl_num::operator+=(const compl_num& other) {
  re += other.re;
  im += other.im;

  return *this;
}

compl_num& compl_num::operator-=(const compl_num& other) {
  re -= other.re;
  im -= other.im;

  return *this;
}

compl_num& compl_num::operator*=(const compl_num& other) {
  re = re * other.re - im * other.im;
  im = re * other.im + im * other.re;

  return *this;
}

compl_num& compl_num::operator/=(const compl_num& other) {
  re = (re * other.re + im * other.im) / (im * im + other.im * other.im);
  im = (im * other.re - re * other.im) / (im * im + other.im * other.im);

  return *this;
}

compl_num& compl_num::operator-() {
  re *= -1;
  im *= -1;

  return *this;
}

compl_num compl_num::operator+(const float num) const{
  compl_num res{re + num, im};
  return res;
}

compl_num compl_num::operator-(const float num) const{
  compl_num res{re - num, im};
  return res;
}

compl_num compl_num::operator*(const float num) const {
  compl_num res{re * num, im * num};
  return res;
}

compl_num compl_num::operator/(const float num) const{
  compl_num res{re / num, im / num};
  return res;
}


compl_num operator*(const float num, compl_num &rhs) {
  rhs.re *= num;
  rhs.im *= num;

  return rhs;
}

bool compl_num::operator==(const compl_num &other) const {
  if (re == other.re && im == other.im)
    return true;

  return false;  
}

bool compl_num::operator!=(const compl_num &other) const {
  if (re != other.re || im != other.im)
    return true;

  return false;  
}