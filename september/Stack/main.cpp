#include <iostream>
#include "includes/headers.hpp"

bool test1();
bool test2();
bool test3();
bool test4();
bool test5();
bool test6();
bool Testing();

int main() {
    if (Testing()) {
        std::cout << "Success" << std::endl;
    }
    else {
        std::cout << "Failure" << std::endl;
    }
    return 0;
}

bool test1() {

    Stack<int> st;
    if (!st.is_empty()) {
        std::cout << "Test 1.1 has failed" << std::endl;
        return false;
    }

    st.push(1);
    if (st.is_empty()) {
        std::cout << "Test 1.2 has failed" << std::endl;
        return false;
    }

    return true;
}

bool test2() {
    Stack<int> st;

    for (int i = 0; i < 32; ++i) {
        st.push (i * 2);
    }

    for (int i = 31; i >= 0; --i) {
        if (st.pop() != 2 * i) {
            std::cout << "Test 2 has failed" << std::endl;
            return false;
        }
    }

    return true;
}

bool test3() {
    Stack<int> st;
    if (st.size() != 0) {
        std::cout << "Test 3.1 has failed" << std::endl;
        return false;
    }

    for (int i = 0; i < 32; ++i) {
        st.push(i + 1);
        if (st.size() != i + 1) {
            std::cout << "Test 3.2 has failed" << std::endl;
            return false;
        }
    }

    for (int i = 31; i >= 0; --i) {
        st.pop();
        if (st.size() != i) {
            std::cout << "Test 3.3 has failed" << std::endl;
            return false;
        }
    }

    return true;
}
bool test4() {
    Stack<int> tmp_1;
    for (int i = 0; i < 50; ++i){
        tmp_1.push(i + 1);
    }

    Stack<int> tmp_2(tmp_1);
    if (tmp_1.size() == tmp_2.size()) {
        for (int i = 49; i >= 0; --i) {
            if (tmp_2.pop() != i + 1) {
                std::cout << "Test 4.1 has failed" << std::endl;
                return false;
            }
        }
        return true;
    }

    else {
        std::cout << "Test 4.2 has failed" << std::endl;
        return false;
    }
}

bool test5() {
    Stack<int> tmp_1;
    for (int i = 0; i < 50; ++i) {
        tmp_1.push(i + 1);
    }

    Stack<int> tmp_2(std::move(tmp_1));
    if (tmp_1.size() == 0 && tmp_2.size() == 50) {
        for (int i = 49; i >= 0; --i) {
            if (tmp_2.pop() != i + 1) {
                std::cout << "Test 5.1 has failed" << std::endl;
                return false;
            }
        }
        return true;
    }

    else {
        std::cout << "Test 5.2 has failed" << std::endl;
        return false;
    }

    return true;
}

bool test6() {
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
                std::cout << "Test 6.1 has failed" << std::endl;
                return false;
            }
        }
        for (int i = 200; i >= 100; --i) {
            if (tmp_1.pop() != i) {
                std::cout << "Test 6.2 has failed" << std::endl;
                return false;
            }
        }
        return true;
    }
    else {
        std::cout << "Test 6.3 has failed" << std::endl;
        return false;
    }
}

bool Testing() {
    bool result = true;

    result = result && test1();
    result = result && test2();
    result = result && test3();
    result = result && test4();
    result = result && test5();
    result = result && test6();

    return result;
}