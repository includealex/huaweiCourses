#ifndef QUEUE_INCLUDES_CIRCULAR_QUEUE_HPP
#define QUEUE_INCLUDES_CIRCULAR_QUEUE_HPP

namespace circular_queue {

template <class T>
class Queue {
 public:
  size_t START_QUEUE_SIZE = 32;

  Queue();
  Queue(const Queue& other);
  Queue(Queue&& other);
  ~Queue();

  void push(T elem);
  void pop();

  size_t size() const;
  const T& front() const;
  const T& rear() const;

  bool is_empty() const;
  bool operator==(const Queue& other) const;
  bool operator!=(const Queue& other) const;

  Queue& operator=(const Queue& other);
  Queue& operator=(Queue&& other);

 private:
  T* data_;
  size_t rear_;
  size_t front_;
  size_t counter_;
  size_t size_;

  void queue_realloc();
};

}  // namespace circular_queue

#endif  // QUEUE_INCLUDES_CIRCULAR_QUEUE_HPP