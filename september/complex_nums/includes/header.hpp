#ifndef complex_nums_includes_header
#define complex_nums_includes_header

struct compl_num {
  float re;
  float im;

  compl_num();
  compl_num(float new_re, float new_im);
  compl_num(const compl_num& other);
  

  float myabs() const;

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

  compl_num& operator+=(const compl_num &other);
  compl_num& operator-=(const compl_num &other);
  compl_num& operator*=(const compl_num &other);
  compl_num& operator/=(const compl_num &other);

  bool operator==(const compl_num &other) const;
  bool operator!=(const compl_num &other) const;
};

compl_num operator*(const float num, const compl_num &rhs);

#endif