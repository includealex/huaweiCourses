#include <algorithm>

#include "../includes/headers.hpp"

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


template class Stack<int>;
template class Stack<long>;
template class Stack<long long>;
template class Stack<unsigned>;
template class Stack<unsigned long long>;
template class Stack<float>;
template class Stack<double>;
template class Stack<char>;