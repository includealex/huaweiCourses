#ifndef HEADER_HPP
#define HEADER_HPP

struct compl_num {
  float re;
  float im;

  compl_num();
  compl_num(float new_re, float new_im);
  compl_num(const compl_num& other);
  

//  float myabs() const;

  compl_num& operator-();
  compl_num& operator=(const compl_num &other);

  compl_num operator+(const float num) const;
  compl_num operator-(const float num) const;
  compl_num operator*(const float num) const;
  compl_num operator/(const float num) const;

  compl_num operator+(const compl_num &other) const;
  compl_num operator-(const compl_num &other) const;
  compl_num operator*(const compl_num &other) const;
  compl_num operator/(const compl_num &other) const;
// 9 tests
  compl_num& operator+=(const compl_num &other);
  compl_num& operator-=(const compl_num &other);
  compl_num& operator*=(const compl_num &other);
  compl_num& operator/=(const compl_num &other);

  bool operator==(const compl_num &other) const;
  bool operator!=(const compl_num &other) const;
};

float myabs(const compl_num &rhs);
compl_num operator*(const float num, const compl_num &rhs);

#endif