#ifndef STACK_INCLUDES_STACK_IMPL_H_
#define STACK_INCLUDES_STACK_IMPL_H_

template <class T>
class Stack {
 public:
  size_t START_STACK_SIZE = 32;

  Stack();
  Stack(const Stack<T>& other);
  Stack(Stack<T>&& other);
  ~Stack();

  size_t size() const;

  const T& top() const;

  void pop();
  void push(T rhs);
  void swap(Stack& other);

  bool is_empty() const;
  bool operator==(const Stack& other) const;
  bool operator!=(const Stack& other) const;

  Stack& operator=(const Stack& other);
  Stack& operator=(Stack&& other);

  template <class U>
  friend void change_factor(Stack<U>& s, double lhs);

 private:
  double factor = 2;
  T* data_;
  size_t size_;
  size_t counter_;
  void stack_realloc();
};

template <class U>
void change_factor(Stack<U>& s, double lhs) {
  s.factor -= lhs;
}

template <class T>
Stack<T>::Stack() : data_(new T[START_STACK_SIZE]), size_(START_STACK_SIZE), counter_(0) {}

template <class T>
Stack<T>::Stack(const Stack<T>& other) {
  data_ = new T[other.size_];
  size_ = other.size_;
  counter_ = other.counter_;
  std::copy(other.data_, other.data_ + other.size_, data_);
}

template <class T>
Stack<T>::Stack(Stack&& other) : data_(other.data_), size_(other.size_), counter_(other.counter_) {
  other.data_ = nullptr;
  other.size_ = other.counter_ = 0;
}

template <class T>
Stack<T>::~Stack() {
  delete[] data_;
}

template <class T>
size_t Stack<T>::size() const {
  return counter_;
}

template <class T>
const T& Stack<T>::top() const {
  return data_[counter_ - 1];
}

template <class T>
void Stack<T>::pop() {
  if (counter_ == 0) {
    std::cout << "Trying to work with non-allocated memory" << std::endl;
    exit(1);
  }

  counter_--;
}

template <class T>
void Stack<T>::push(T rhs) {
  if (counter_ == size_) {
    stack_realloc();
  }

  data_[counter_] = rhs;
  counter_++;
}

template <class T>
void Stack<T>::swap(Stack& other) {
  Stack tmp = std::move(*this);
  *this = std::move(other);
  other = std::move(tmp);
}

template <class T>
bool Stack<T>::is_empty() const {
  return counter_ == 0 ? true : false;
}

template <class T>
bool Stack<T>::operator==(const Stack<T>& other) const {
  if (counter_ != other.counter_)
    return false;

  for (size_t i = 0; i < counter_; ++i) {
    if (data_[i] != other.data_[i])
      return false;
  }

  return true;
}

template <class T>
bool Stack<T>::operator!=(const Stack<T>& other) const {
  return !(*this == other);
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other) {
  if (this == &other) {
    return *this;
  }
  delete[] data_;
  size_ = other.size_;
  counter_ = other.counter_;
  data_ = new T[size_];
  std::copy(other.data_, other.data_ + size_, data_);
  return *this;
}

template <class T>
Stack<T>& Stack<T>::operator=(Stack<T>&& other) {
  if (this != &other) {
    delete[] data_;

    size_ = other.size_;
    counter_ = other.counter_;
    data_ = other.data_;
    other.data_ = nullptr;
    other.size_ = other.counter_ = 0;
  }

  return *this;
}

template <class T>
void Stack<T>::stack_realloc() {
  T* tmp = data_;
  auto newSize = static_cast<uint32_t>(static_cast<double>(size_) * factor);
  data_ = new T[newSize];
  std::copy(tmp, tmp + size_, data_);
  delete[] tmp;
  size_ = static_cast<size_t>(static_cast<double>(size_) * factor);
}

#endif  // STACK_INCLUDES_STACK_IMPL_H_