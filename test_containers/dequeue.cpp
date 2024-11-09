#include <iostream>
#include <deque>

int main() {
    std::deque<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_front(0);

    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }
    return 0;
}
