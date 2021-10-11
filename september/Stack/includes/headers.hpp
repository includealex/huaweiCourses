#ifndef STACK_INCLUDES_HEADERS_H_
#define STACK_INCLUDES_HEADERS_H_

template<class T>
class Stack {

public:
    Stack();
    Stack(const Stack& other);
    Stack(Stack&& other);
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

#endif //STACK_INCLUDES_HEADERS_H_