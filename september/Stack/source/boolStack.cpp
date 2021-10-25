#include <utility>
#include <cstddef>
#include <iostream>

#include "../includes/Stack.h"

Stack<bool>::Stack() : data_(new uint32_t[START_STACK_SIZE]),
                       size_((START_STACK_SIZE + 31) / 8),
                       counter_(0) {}

Stack<bool>::Stack(const Stack& other) {
    data_ = new uint32_t[(other.size_ + 31) / 8];
    size_ = other.size_;
    counter_ = other.counter_;
    std::copy(other.data_,
              other.data_ + other.size_,
              data_);
}

Stack<bool>::Stack(Stack&& other) : data_(other.data_), 
                                   size_(other.size_),
                                   counter_(other.counter_)    
{
    other.data_ = nullptr;
    other.size_ = other.counter_ = 0;
}

Stack<bool>::~Stack() {
    delete [] data_;
}

size_t Stack<bool>::size() const {
    return counter_;
}

bool Stack<bool>::is_empty() const {
    return counter_ == 0 ? true : false;
}

bool Stack<bool>::top() const {
    uint32_t containElem = data_[(counter_ - 1)  / 8];
    containElem  = containElem >> ((counter_ - 1) % 8);
    containElem &= 1;
    return containElem;
}

void Stack<bool>::pop() {
    uint32_t lhs =  data_[(--counter_) / 8];
    lhs = lhs >> (size_ % 8);
    lhs &= 1;
}

void Stack<bool>::push(bool rhs) {
    if (counter_ == size_) {
        uint32_t* arr  = new uint32_t [2 * ((counter_ + 31) / 8)];
        std::copy(data_, data_ + (size_ + 31) / 8, arr);
        delete[] data_;

        data_ = arr;
        counter_ = 2 * ((counter_ + 31) / 8) * 8;
    }

    int i = size_ % 8;
    data_[size_ / 8] = ((data_[size_ / 8] & (~(1 << i))) + (rhs << i));
    counter_++;
}

void Stack<bool>::swap(Stack<bool>& other) {
    Stack tmp = std::move(*this);
    *this = std::move(other);
    other = std::move(tmp);
}

bool Stack<bool>::operator== (const Stack<bool>& other) const {
    if (counter_ != other.counter_)
        return false;

    for (int i = 0; i < counter_; ++i) {
        if (data_[i] != other.data_[i])
            return false;
    }

    for (int i = 0; i < counter_ % 8; ++i) {
        uint32_t lhs = data_[(counter_ - 1) / 8];
        lhs = lhs >> (i);
        lhs &= 1;

        uint32_t rhs = other.data_[(counter_ - 1) / 8];
        rhs = rhs >> (i);
        rhs &= 1;

        if (rhs != lhs)
            return false;
    }

    return true;
}

bool Stack<bool>::operator!=(const Stack<bool> &other) const{
    return !(operator==(other));
}

Stack<bool>& Stack<bool>::operator= (const Stack<bool>& other) {
    if (this != &other) {
      delete [] data_;

      size_ = other.size_;
      counter_ = other.counter_;
      data_ = new uint32_t [(size_ + 31) / 8];

    }

    return *this;
}

Stack<bool>& Stack<bool>::operator= (Stack<bool>&& other) {
    if (this != &other) {
      delete [] data_;

      size_ = other.size_;
      counter_ = other.counter_;
      data_ = other.data_;
      other.data_ = nullptr;
      other.size_ = other.counter_ = 0;
    }

    return *this;
}