#ifndef QUEUE_INCLUDES_STACK_QUEUE_HPP
#define QUEUE_INCLUDES_STACK_QUEUE_HPP

#include "Stack/Stack_impl.hpp"

namespace stack_queue {

template <typename T>
class Queue {
 public:
  Queue();
  Queue(const Queue& other);
  Queue(Queue&& other) noexcept;
  ~Queue() = default;

  void push(T elem);
  void pop();

  size_t size() const;
  const T& front();
  const T& rear();

  bool is_empty() const;
  bool operator==(Queue& other);
  bool operator!=(Queue& other);

  Queue& operator=(const Queue& other);
  Queue& operator=(Queue&& other) noexcept;

 private:
  size_t counter_;
  T last_;
  Stack<T> st1_;
  Stack<T> st2_;
  void mvto2st();
};

}  // namespace stack_queue

#endif  // QUEUE_INCLUDES_STACK_QUEUE_HPP