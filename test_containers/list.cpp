#include <iostream>
#include <list>

int main() {
    std::list<int> numbers;
    numbers.push_front(3);
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_front(0);
    numbers.push_back(3);

    for (std::list<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    return 0;
}
