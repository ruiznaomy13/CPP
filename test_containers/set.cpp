#include <iostream>
#include <set>

int main() {
    std::set<int> numbers;
    numbers.insert(3);
    numbers.insert(1);
    numbers.insert(2);

    for (std::set<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    return 0;
}
