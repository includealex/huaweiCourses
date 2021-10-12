#ifndef STACK_INCLUDES_HEADERS_H_
#define STACK_INCLUDES_HEADERS_H_

#include <cstdint>

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


#endif //STACK_INCLUDES_HEADERS_H_