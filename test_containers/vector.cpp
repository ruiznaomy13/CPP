#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> numbers;
    numbers.push_back("Hola 0");
    numbers.push_back("Hola 1");
    numbers.push_back("Hola 2");
    // numbers.push_back(2);
    numbers.push_back("Hola 3");

    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << "\n";
    }
    return 0;
}
