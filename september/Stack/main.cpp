#include <iostream>
#include "includes/headers.hpp"

bool test_push();
bool test_is_empty();
bool test_pop();
bool test_size();
bool test_copy_constr();
bool test_move_constr();
bool test_swap();
bool start_tests();

int main() {
    if (start_tests()) {
        std::cout << "All the tests have been successfully passed" << std::endl;
    }
    else {
        std::cout << "Some tests have failed" << std::endl;
    }
    return 0;
}

bool test_push() {
    Stack<int> st;
    for (int i = 0; i < 32; ++i) {
        st.push(i + 1);
        if (st.top() != i + 1) {
            std::cout << "Test for push() method has failed" << std::endl;
            return false;
        }
    }
    for (int i = 31; i >= 0; --i) {
        if (st.top() != i + 1) {
            std::cout << "Test for push() method has failed" << std::endl;
            return false;
        }
        st.pop();
    }
    return true;
}

bool test_is_empty() {
    Stack<int> st;
    if (!st.is_empty()) {
        std::cout << "Test for is_empty method has failed" << std::endl;
        return false;
    }
    st.push(3);
    if (st.is_empty()) {
        std::cout << "Test for is_empty method has failed" << std::endl;
        return false;
    }
    return true;
}

bool test_pop() {
    Stack<int> st;
    for (int i = 0; i < 32; ++i) {
        st.push(i + 1);
    }
    for (int i = 31; i >= 0; --i) {
        if (st.pop() != i + 1) {
            std::cout << "Test for pop() method has failed" << std::endl;
            return false;
        }
    }
    return true;
}

bool test_size() {
    Stack<int> st;
    if (st.size() != 0) {
        std::cout << "Test for size() method has failed" << std::endl;
        return false;
    }
    for (int i = 0; i < 32; ++i) {
        st.push(i + 1);
        if (st.size() != i + 1) {
            std::cout << "Test for size() method has failed" << std::endl;
            return false;
        }
    }
    for (int i = 31; i >= 0; --i) {
        st.pop();
        if (st.size() != i) {
            std::cout << "Test for size() method has failed" << std::endl;
            return false;
        }
    }
    return true;
}
bool test_copy_constr() {
    Stack<int> tmp_1;
    for (int i = 0; i < 50; ++i)
        tmp_1.push(i + 1);
    Stack<int> tmp_2(tmp_1);
    if (tmp_1.size() == tmp_2.size()) {
        for (int i = 49; i >= 0; --i) {
            if (tmp_2.pop() != i + 1) {
                std::cout << "Test for copy constructor has failed" << std::endl;
                return false;
            }
        }
        return true;
    }
    else {
        std::cout << "Test for copy constructor has failed" << std::endl;
        return false;
    }
}

bool test_move_constr() {
    Stack<int> tmp_1;
    for (int i = 0; i < 50; ++i)
        tmp_1.push(i + 1);
    Stack<int> tmp_2(std::move(tmp_1));
    if (tmp_1.size() == 0 && tmp_2.size() == 50) {
        for (int i = 49; i >= 0; --i) {
            if (tmp_2.pop() != i + 1) {
                std::cout << "Test for move constructor has failed" << std::endl;
                return false;
            }
        }
        return true;
    }
    else {
        std::cout << "Test for move constructor has failed" << std::endl;
        return false;
    }
    return true;
}

bool test_swap() {
    Stack<int> tmp_1;
    Stack<int> tmp_2;
    for (int i = 0; i < 50; ++i) {
        tmp_1.push(i + 1);
    }
    for (int i = 100; i <= 200; ++i) {
        tmp_2.push(i);
    }
    tmp_1.swap(tmp_2);
    if (tmp_1.size() == 101 && tmp_2.size() == 50) {
        for (int i = 49; i >= 0; --i) {
            if (tmp_2.pop() != i + 1) {
                std::cout << "Test for swap method has failed" << std::endl;
                return false;
            }
        }
        for (int i = 200; i >= 100; --i) {
            if (tmp_1.pop() != i) {
                std::cout << "Test for swap method has failed" << std::endl;
                return false;
            }
        }
        return true;
    }
    else {
        std::cout << "Test for swap method has failed" << std::endl;
        return false;
    }
}

bool start_tests() {
    bool result = true;

    result = result && test_push();
    result = result && test_is_empty();
    result = result && test_pop();
    result = result && test_size();
    result = result && test_copy_constr();
    result = result && test_move_constr();
    result = result && test_swap();

    return result;
}