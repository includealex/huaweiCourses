#ifndef STACK_INCLUDES_HEADERS_H_
#define STACK_INCLUDES_HEADERS_H_

template<typename T>
class Stack {

public:
    Stack();
    Stack(const Stack& another);
    Stack(Stack&& another);
    ~Stack();
    
    bool is_empty() const;
    int size() const;
    T top() const;
    T pop();
    void push(T el);
    void swap(Stack& another);

    bool operator== (const Stack& another) const;
    bool operator!= (const Stack& another) const;
    Stack& operator= (const Stack& another);
    Stack& operator= (Stack&& another);

private:
    const int START_STACK_SIZE = 32;
    T* data_;
    int size_;
    int counter_;
    void stack_realloc();

};

#endif //STACK_INCLUDES_HEADERS_H_