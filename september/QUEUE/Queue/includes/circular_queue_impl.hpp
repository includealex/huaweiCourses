#ifndef QUEUE_INCLUDES_CIRCULAR_QUEUE_IMPL_HPP
#define QUEUE_INCLUDES_CIRCULAR_QUEUE_IMPL_HPP

#include "circular_queue.hpp"

namespace circular_queue {

template <class T>
Queue<T>::Queue()
    : data_(new T[START_QUEUE_SIZE]), rear_(0), front_(0), counter_(0), size_(START_QUEUE_SIZE) {}

template <class T>
Queue<T>::Queue(const Queue& other) {
  data_ = new T[other.size_];
  rear_ = other.rear_;
  front_ = other.front_;
  counter_ = other.counter_;
  size_ = other.size_;

  std::copy(other.data_, other.data_ + other.size_, data_);
}

template <class T>
Queue<T>::Queue(Queue&& other)
    : data_(other.data_),
      rear_(other.rear_),
      front_(other.front_),
      counter_(other.counter_),
      size_(other.size_) {
  other.data_ = nullptr;
  other.size_ = other.counter_ = other.front_ = other.rear_ = 0;
}

template <class T>
Queue<T>::~Queue() {
  delete[] data_;
}

template <class T>
void Queue<T>::push(T elem) {
  if (counter_ == size_) {
    queue_realloc();
  }

  data_[rear_ % size_] = elem;
  ++rear_;
  ++counter_;
}

template <class T>
void Queue<T>::pop() {
  --counter_;
  ++front_;
}

template <class T>
size_t Queue<T>::size() const {
  return counter_;
}

template <class T>
const T& Queue<T>::front() const {
  size_t tmp = front_;

  return data_[tmp];
}

template <class T>
const T& Queue<T>::rear() const {
  size_t tmp = rear_;
  size_t val = size_;

  --tmp;
  tmp %= val;

  return data_[tmp];
}

template <class T>
bool Queue<T>::is_empty() const {
  return counter_ == 0;
}

template <class T>
bool Queue<T>::operator==(const Queue<T>& other) const {
  if (counter_ != other.counter_) {
    return false;
  }

  for (int i = 0; i < counter_; ++i) {
    if (data_[(front_ + i) % size_] != other.data[(front_ + i) % size_]) {
      return false;
    }
  }

  return true;
}

template <typename T>
bool Queue<T>::operator!=(const Queue<T>& other) const {
  return !(*this == other);
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other) {
  if (this == &other) {
    return *this;
  }

  rear_ = other.rear_;
  front_ = other.front_;
  size_ = other.size_;
  counter_ = other.counter_;
  data_ = new T[size_];

  std::copy(other.data_, other.data_ + size_, data_);

  return *this;
}

template <class T>
Queue<T>& Queue<T>::operator=(Queue<T>&& other) {
  if (this != &other) {
    delete[] data_;

    rear_ = other.rear_;
    front_ = other.front_;
    size_ = other.size_;
    counter_ = other.counter_;
    data_ = other.data_;
    other.data_ = nullptr;
    other.size_ = other.counter_ = 0;
  }

  return *this;
}

template <class T>
void Queue<T>::queue_realloc() {
  T* tmp = data_;
  auto newSize = (size_ * 2);
  data_ = new T[newSize];

  std::copy(tmp, tmp + size_, data_);
  delete[] tmp;
  size_ = newSize;
}

}  // namespace circular_queue

#endif  // QUEUE_INCLUDES_CIRCULAR_QUEUE_IMPL_HPP