#ifndef STACK_INCLUDES_HEADERS_H_
#define STACK_INCLUDES_HEADERS_H_

#include <cstdint>
#include <algorithm>

template<class T>
class Stack {

public:
    Stack();
    Stack(const Stack<T>& other);
    Stack(Stack<T>&& other);
    ~Stack();

    int size() const;
    T pop();

    void push(T rhs);
    void swap(Stack& other);

    bool is_empty() const;
    bool operator== (const Stack& other) const;
    bool operator!= (const Stack& other) const;

    Stack& operator= (const Stack& other);
    Stack& operator= (Stack&& other);

private:
    const int START_STACK_SIZE = 32;
    T* data_;
    int size_;
    int counter_;
    void stack_realloc();
};

// Bool Stack

template <>
class Stack <bool> {

public:
    Stack();
    Stack(const Stack& other);
    Stack(Stack&& other);
    ~Stack();

    int size() const;
    bool pop();

    void push(bool rhs);
    void swap(Stack<bool>& other);

    bool is_empty() const;
    bool operator== (const Stack<bool>& other) const;
    bool operator!= (const Stack<bool>& other) const;

    Stack& operator= (const Stack& other);
    Stack& operator= (Stack&& other);



private:
    const int START_STACK_SIZE = 32;
    uint32_t* data_;
    int size_;
    int counter_;
//    void stack_realloc();    
};

// 1. Stack no-bulls functions
template<class T>
Stack<T>::Stack() : data_(new T[START_STACK_SIZE]),
                    size_(START_STACK_SIZE),
                    counter_(0) {}

template<class T>
Stack<T>::Stack(const Stack<T>& other) {
    data_ = new T[other.size_];
    size_ = other.size_;
    counter_ = other.counter_;
    std::copy(other.data_,
              other.data_ + other.size_,
              data_);
}

template<class T>
Stack<T>::Stack(Stack&& other) : data_(other.data_), 
                                 size_(other.size_),
                                 counter_(other.counter_)    
{
    other.data_ = nullptr;
    other.size_ = other.counter_ = 0;
}

template<class T>
Stack<T>::~Stack() {
    delete [] data_;
}

template<class T>
int Stack<T>::size() const {
    return counter_;
}


template<class T>
T Stack<T>::pop() {
    return data_[--counter_];
}

template<class T>
void Stack<T>::push(T rhs) {
    if (counter_ == size_) {
        stack_realloc();
    }
    data_[counter_++] = rhs;
}

template<class T>
void Stack<T>::swap(Stack& other) {
    Stack tmp = std::move(*this);
    *this = std::move(other);
    other = std::move(tmp);
}

template<class T>
bool Stack<T>::is_empty() const {
    return counter_ == 0 ? true : false;
}

template<class T>
bool Stack<T>::operator== (const Stack<T>& other) const {
    if (counter_ != other.counter_)
        return false;

    for (int i = 0; i < counter_; ++i) {
        if (data_[i] != other.data_[i])
            return false;
    }

    return true;
}

template<class T>
bool Stack<T>::operator!= (const Stack<T>& other) const {
    return !(*this == other);
}

template<class T>
Stack<T>& Stack<T>::operator= (const Stack<T>& other) {
    if (this == &other){
        return *this;
    }
    delete [] data_;
    size_ = other.size_;
    counter_ = other.counter_;
    data_ = new T[size_];
    std::copy(other.data_, other.data_ + size_, data_);
    return *this;
}

template<class T>
Stack<T>& Stack<T>::operator= (Stack<T>&& other) {
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

template<class T>
void Stack<T>::stack_realloc() {
    T* tmp = data_;
    data_ = new T[size_ * 2];
    std::copy(tmp, tmp + size_, data_);
    size_ *= 2;
}

// 2. Stack bulls functions

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

int Stack<bool>::size() const {
    return counter_;
}

bool Stack<bool>::is_empty() const {
    return counter_ == 0 ? true : false;
}

bool Stack<bool>::pop() {
    uint32_t lhs =  data_[(--counter_) / 8];
    lhs = lhs >> (size_ % 8);
    lhs &= 1;

    return lhs;
}

void Stack<bool>::push(bool rhs) {
    if (counter_ == size_) {
        uint32_t* arr  = new uint32_t [2 * ((counter_ + 7) / 8)];
        std::copy(data_, data_ + (size_ + 7) / 8, arr);
        delete[] data_;

        data_ = arr;
        counter_ = 2 * ((counter_ + 7) / 8) * 8;
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
      data_ = new uint32_t [(size_ + 7) / 8];

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

#endif //STACK_INCLUDES_HEADERS_H_