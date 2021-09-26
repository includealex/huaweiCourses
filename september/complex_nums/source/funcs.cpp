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
