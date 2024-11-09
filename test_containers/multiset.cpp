#include <iostream>
#include <set>

int main() {
    std::multiset<int> numbers;
    numbers.insert(1);
    numbers.insert(2);
    numbers.insert(1); // duplicate allowed

    for (std::multiset<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    return 0;
}
