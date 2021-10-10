#include <utility>
#include <algorithm>

#include "../includes/headers.hpp"

template<typename T>
Stack<T>::Stack() : data_(new T[START_STACK_SIZE]),
                    size_(START_STACK_SIZE),
                    counter_(0) {}

template<typename T>
Stack<T>::Stack(const Stack<T>& another) {
    data_ = new T[another.size_];
    size_ = another.size_;
    counter_ = another.counter_;
    std::copy(another.data_,
              another.data_ + another.size_,
              data_);
}

template<typename T>
Stack<T>::Stack(Stack&& another) : data_(another.data_), 
                                   size_(another.size_),
                                   counter_(another.counter_)    
{
    another.data_ = nullptr;
    another.size_ = another.counter_ = 0;
}

template<typename T>
Stack<T>::~Stack() {
    delete [] data_;
}

template<typename T>
bool Stack<T>::is_empty() const {
    return counter_ == 0 ? true : false;
}

template<typename T>
int Stack<T>::size() const {
    return counter_;
}

template<typename T>
T Stack<T>::top() const {
    return data_[counter_ - 1];
}

template<typename T>
T Stack<T>::pop() {
    return data_[--counter_];
}

template<typename T>
void Stack<T>::stack_realloc() {
    T* tmp = data_;
    data_ = new T[size_ * 2];
    std::copy(tmp, tmp + size_, data_);
    size_ *= 2;
}

template<typename T>
void Stack<T>::push(T el) {
    if (counter_ == size_) {
        stack_realloc();
    }
    data_[counter_++] = el;
}

template<typename T>
void Stack<T>::swap(Stack& another) {
    Stack tmp = std::move(*this);
    *this = std::move(another);
    another = std::move(tmp);
}

template<typename T>
bool Stack<T>::operator== (const Stack<T>& another) const {
    if (counter_ != another.counter_)
        return false;
    for (int i = 0; i < counter_; ++i) {
        if (data_[i] != another.data_[i])
            return false;
    }
    return true;
}

template<typename T>
bool Stack<T>::operator!= (const Stack<T>& another) const {
    return !(*this == another);
}

template<typename T>
Stack<T>& Stack<T>::operator= (const Stack<T>& another) {
    if (this == &another){
        return *this;
    }
    delete [] data_;
    size_ = another.size_;
    counter_ = another.counter_;
    data_ = new T[size_];
    std::copy(another.data_, another.data_ + size_, data_);
    return *this;
}

template<typename T>
Stack<T>& Stack<T>::operator= (Stack<T>&& another) {
    if (this == &another) {
        return *this;
    }
    delete [] data_;
    size_ = another.size_;
    counter_ = another.counter_;
    data_ = another.data_;
    another.data_ = nullptr;
    another.size_ = another.counter_ = 0;
    return *this;
}

template class Stack<int>;
template class Stack<long>;
template class Stack<long long>;
template class Stack<unsigned>;
template class Stack<unsigned long long>;
template class Stack<float>;
template class Stack<double>;
template class Stack<char>;