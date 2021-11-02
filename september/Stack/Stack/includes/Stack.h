#ifndef STACK_INCLUDES_STACK_H_
#define STACK_INCLUDES_STACK_H_

#include "Stack_impl.h"

template <>
class Stack<bool> {
 public:
  size_t START_STACK_SIZE = 32;

  Stack();
  Stack(const Stack& other);
  Stack(Stack&& other) noexcept;
  ~Stack();

  size_t size() const;

  bool top() const;

  void pop();
  void push(bool rhs);
  void swap(Stack<bool>& other);

  bool is_empty() const;
  bool operator==(const Stack<bool>& other) const;
  bool operator!=(const Stack<bool>& other) const;

  Stack& operator=(const Stack& other);
  Stack& operator=(Stack&& other) noexcept;

 private:
  uint32_t* data_;
  size_t size_;
  size_t counter_;
  void stack_realloc();
};

#endif  // STACK_INCLUDES_STACK_H_