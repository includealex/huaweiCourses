#include <iostream>
#include <vector>

#include "includes/Stack.h"

bool test_top();
bool test_size();
bool all_tests();

int main() {
    if(all_tests() != true) {
        std::cout << "Failure" << std::endl;
    }

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


bool all_tests() {
    bool result = true;

    result = result && test_top();
    result = result && test_size();

    return result;
}