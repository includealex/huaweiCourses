#include <iostream>
#include <vector>

#include "includes/Stack.h"
#include "includes/Stack_impl.h"

bool test_top();
bool test_size();
bool test_pop();
bool test_is_empty();
bool test_equality();
bool test_swap();
bool test_btop();
bool test_bsize();
bool test_bis_empty();
bool all_tests();

int main() {
    if(all_tests() != true) {
        std::cout << "Failure" << std::endl;
        return 1;
    }

    std::cout << "Success" << std::endl;
    return 0;
}

bool test_top() {
    Stack<uint32_t> s1;

    for(int i = 0; i < 1001; ++i) {
        s1.push(i * 2);
    }

    if(s1.top() != 2000) {
        std::cout << s1.top() << std::endl;
        std::cout << "test_top has failed" << std::endl;
        return false;
    }

    return true;
}

bool test_size() {
    Stack<uint32_t> s2;

    for(int i = 0; i < 1e5; ++i) {
        s2.push(i * 2);
    }

    if(s2.size() != 1e5) {
        std::cout << "test_size has failed" << std::endl;
        return false;
    }

    return true;
}

bool test_pop() {
    Stack<uint32_t> s3;

    for(uint32_t i = 0; i < 400; ++i) {
        s3.push(i);
    }

    for (uint32_t i = 0; i < 250; ++i) {
        s3.pop();
    }

    if(s3.size() != 150) {
        std::cout << s3.size() << std::endl;
        std::cout << "test_pop has failed" << std::endl;
        return false;
    }

    return true;
}

bool test_is_empty() {
    Stack<uint32_t> s4;

    if(!s4.is_empty()) {
        std::cout << "test_is_empty has failed" << std::endl;
        return false;
    }

    s4.push(1);
    if(s4.is_empty()){
        std::cout << "test_is_empty has failed" << std::endl;
        return false;        
    }

    return true;
}

bool test_equality() {
    Stack<uint32_t> s1;
    Stack<uint32_t> s2;

    if(!(s1 == s2)) {
        std::cout << "test_equality has failed" << std::endl;
        return false;
    }

    return true;
}

bool test_swap() {
    Stack<uint32_t> s1, s11, s2, s21;

    for(uint32_t i = 0; i < 10; ++i) {
        s1.push(i);
    }
    s2.push(13);

    s11 = s1;
    s21 = s2;

    s1.swap(s2);

    if(!(s1 == s21 && s2 == s11)) {
        std::cout << "test_swap has failed" << std::endl;
        return false;
    }

    return true;
}

bool test_btop() {
    Stack<bool> s1;

    std::vector<bool> v1 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};

    for(bool item: v1){
        s1.push(item);
    }

    if(s1.top() != 1) {
        std::cout << s1.top();
        std::cout << "test_btop has failed" << std::endl;
        return false;
    }

    return true;
}

bool test_bsize() {
    Stack<bool> s1;

    for (int i = 0; i < 1e4; ++i) {
        s1.push(i % 2);
    }

    if(s1.size() != 10057) {
        std::cout << "test_bsize has failed" << std::endl;
        return false;
    }

    return true;
}

bool test_bis_empty() {
    Stack<bool> s1;

    if(!s1.is_empty()) {
        std::cout << "test_bis_empty has failed" << std::endl;
        return false;
    }

    return true;
}

bool all_tests() {
    bool result = true;

    result = result && test_top();
    result = result && test_size();
    result = result && test_pop();
    result = result && test_is_empty();
    result = result && test_equality();
    result = result && test_swap();
    result = result && test_btop();
    result = result && test_bsize();
    result = result && test_bis_empty();

    return result;
}