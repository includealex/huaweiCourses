#include <cstddef>
#include <iostream>
#include <utility>

#include "../includes/Stack.h"

Stack<bool>::Stack()
    : data_(new uint32_t[START_STACK_SIZE]), size_(START_STACK_SIZE), counter_(0) {}

Stack<bool>::Stack(const Stack& other) {
  data_ = new uint32_t[other.size_];
  size_ = other.size_;
  counter_ = other.counter_;
  std::copy(other.data_, other.data_ + other.size_, data_);
}

Stack<bool>::Stack(Stack&& other) noexcept
    : data_(other.data_), size_(other.size_), counter_(other.counter_) {
  other.data_ = nullptr;
  other.size_ = other.counter_ = 0;
}

Stack<bool>::~Stack() {
  delete[] data_;
}

size_t Stack<bool>::size() const {
  return counter_;
}

bool Stack<bool>::is_empty() const {
  return counter_ == 0 /*? true : false*/;
}

// bool Stack<bool>::top() const {
//    uint32_t containElem = data_[size_ - (counter_ / 32)];
//    containElem  = containElem >> ((counter_ - 1) % 32);
//    containElem &= 1;
//    return containElem;
//}

bool Stack<bool>::top() const {
  uint32_t num_of_bit = counter_ % 32 - 1;
  uint32_t num_of_byte = counter_ / 32;

  bool elem = static_cast<bool>((data_[num_of_byte] & (1 << num_of_bit)) >> num_of_bit);

  return elem;
}

void Stack<bool>::pop() {
  if (counter_ == 0) {
    std::cout << "Trying to get data from non-pushed memory" << std::endl;
    exit(1);
  }

  counter_--;
}

// void Stack<bool>::push(bool rhs) {
//    if (counter_ == size_) {
//        stack_realloc();
//    }
//
//    uint32_t num_of_bit  = 32 - 1 - (uint32_t)(counter_ % 8);
//    uint32_t num_of_byte = (uint32_t)(size_ - 1 - counter_ / 8);
//
//    if(rhs == 1) {
//        data_[num_of_byte] = (1 << num_of_bit);
//    }
//    else if(rhs == 0) {
//        data_[num_of_byte] &= ~(1 << num_of_bit);
//    }
//
//    counter_++;
//}

void Stack<bool>::push(bool rhs) {
  if (counter_ == size_) {
    stack_realloc();
  }

  uint32_t num_of_bit = counter_ % 32;
  uint32_t num_of_byte = counter_ / 32;

  if (rhs) {
    data_[num_of_byte] = (1 << num_of_bit);
  } else if (!rhs) {
    data_[num_of_byte] &= ~(1 << num_of_bit);
  }

  counter_++;
}

void Stack<bool>::swap(Stack<bool>& other) {
  Stack tmp = std::move(*this);
  *this = std::move(other);
  other = std::move(tmp);
}

// bool Stack<bool>::operator== (const Stack<bool>& other) const{
//    if (counter_ != other.counter_) {
//        return false;
//    }
//
//    for (uint32_t i = 0; i < size_ / 2; ++i) {
//        if (data_[i] != other.data_[i])
//            return false;
//    }
//
//    size_t oth_count = (counter_ % (size_ * 16)) / 32;
//
//    for(uint32_t i = 0; i < oth_count; ++i) {
//        if(data_[size_ - i] != other.data_[size_ - i]) {
//            return false;
//        }
//    }
//
//    uint32_t lhs = data_[size_ - oth_count];
//    uint32_t rhs = other.data_[size_ - oth_count];
//
//    size_t bit_val = (counter_ % (size_ * 16)) % 32;
//
//    if((lhs % bit_val) != (rhs % bit_val)) {
//        return false;
//    }
//
//    return true;
//}

bool Stack<bool>::operator==(const Stack<bool>& other) const {
  if (counter_ != other.counter_) {
    return false;
  }

  uint32_t num_of_bit = counter_ % 32;
  uint32_t num_of_byte = counter_ / 32;

  for (uint32_t i = 0; i < num_of_byte; ++i) {
    if (data_[i] != other.data_[i]) {
      return false;
    }
  }

  for (uint32_t i = 0; i < num_of_bit; ++i) {
    if ((data_[num_of_byte] & (1 << i)) != (other.data_[num_of_byte] & (1 << i))) {
      return false;
    }
  }

  return true;
}

bool Stack<bool>::operator!=(const Stack<bool>& other) const {
  return !(operator==(other));
}

Stack<bool>& Stack<bool>::operator=(const Stack<bool>& other) {
  if (this != &other) {
    delete[] data_;

    size_ = other.size_;
    counter_ = other.counter_;
    data_ = new uint32_t[size_];
  }

  return *this;
}

Stack<bool>& Stack<bool>::operator=(Stack<bool>&& other) noexcept {
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

void Stack<bool>::stack_realloc() {
  uint32_t* tmp = data_;
  //    delete[] data_;
  auto new_size = static_cast<uint32_t>(size_ * 2);
  data_ = new uint32_t[new_size];
  std::copy(tmp, tmp + size_, data_);
  size_ *= 2;
}