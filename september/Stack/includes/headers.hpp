#ifndef STACK_INCLUDES_HEADERS_HPP
#define STACK_INCLUDES_HEADERS_HPP

struct Stack {
  Stack();
  Stack(Stack const & other);
  ~Stack();

  bool is_empty() const;
  void push(int data);
  int pop;
  int size() const;
  int & top();

  Stack & operator = (Stack const & other);
  bool operator == (Stack const & other) const;
  bool operator != (Stack const & other) const;

  const int START_STACK_SIZE_ = 50;//That thing should be changed!!!

  int *data;
  int size_;
  int counter_;
};

#endif