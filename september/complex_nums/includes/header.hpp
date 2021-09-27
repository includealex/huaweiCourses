struct compl_num {
  float re;
  float im;

  compl_num();
  compl_num(float new_re, float new_im);
  compl_num(const compl_num& other);
  

  compl_num& operator-();
  compl_num& operator=(const compl_num &other);
  compl_num& operator*(const float num);

  compl_num operator+(const compl_num &other) const;
  compl_num operator-(const compl_num &other) const;
  compl_num operator*(const compl_num &other) const;
  compl_num operator/(const compl_num &other) const;




  float abs() const;
};