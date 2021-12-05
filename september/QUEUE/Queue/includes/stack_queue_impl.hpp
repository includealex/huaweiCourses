#ifndef QUEUE_INCLUDES_STACK_QUEUE_IMPL_HPP
#define QUEUE_INCLUDES_STACK_QUEUE_IMPL_HPP

#include "../../Stack/includes/Stack_impl.hpp"
#include "stack_queue.hpp"

namespace stack_queue {

template <typename T>
Queue<T>::Queue() : counter_(0) {}

template <typename T>
Queue<T>::Queue(const Queue& other)
    : counter_(other.counter_), last_(other.last_), st1_(other.st1_), st2_(other.st2_) {}

template <typename T>
Queue<T>::Queue(Queue&& other) noexcept
    : counter_(other.counter_),
      last_(other.last_),
      st1_(std::move(other.st1_)),
      st2_(std::move(other.st2_)) {}

template <typename T>
void Queue<T>::mvto2st() {
  while (!st1_.is_empty()) {
    auto elem = st1_.top();

    st1_.pop();
    st2_.push(elem);
  }
}

template <typename T>
void Queue<T>::push(T elem) {
  st1_.push(elem);
  last_ = elem;
  ++counter_;
}

template <typename T>
void Queue<T>::pop() {
  if (st2_.is_empty() && (!st1_.is_empty())) {
    mvto2st();
  }

  st2_.pop();
  --counter_;
}

template <typename T>
const T& Queue<T>::front() {
  if (st2_.is_empty()) {
    mvto2st();
  }

  return st2_.top();
}

template <typename T>
const T& Queue<T>::rear() {
  return last_;
}

template <typename T>
size_t Queue<T>::size() const {
  return counter_;
}

template <typename T>
bool Queue<T>::is_empty() const {
  return (counter_ == 0);
}

template <typename T>
bool Queue<T>::operator==(Queue<T>& other) {
  if (counter_ != other.counter_) {
    return false;
  }

  if (counter_ == 0) {
    return true;
  }

  if (st1_ == other.st1_ && st2_ == other.st2_ && last_ == other.last_) {
    return true;
  }

  return false;
}

template <typename T>
bool Queue<T>::operator!=(Queue<T>& other) {
  return !(*this == other);
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other) {
  if (this == &other) {
    return *this;
  }

  st1_ = other.st1_;
  st2_ = other.st2_;
  last_ = other.last_;
  counter_ = other.counter_;
  return *this;
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue<T>&& other) noexcept {
  if (this == &other) {
    return *this;
  }

  st1_ = std::move(other.st1_);
  st2_ = std::move(other.st2_);
  counter_ = other.counter_;
  last_ = other.last_;
  return *this;
}

}  // namespace stack_queue

#endif  // QUEUE_INCLUDES_STACK_QUEUE_IMPL_HPP