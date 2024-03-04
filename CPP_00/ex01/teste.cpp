#include <iostream>
#include <string>

std::string truncateString(const std::string& str, int length) {
    std::string result = str; // Copiamos la cadena original

    if (length >= 0 && length < str.length()) {
        result.erase(length); // Eliminamos desde la posición 'length' hasta el final
    }

    return result;
}

int main() {
    std::string input = "Hello, World!";
    std::cout << "Original string: " << input << std::endl;

    std::string truncated = truncateString(input, 5); // Eliminar desde la posición 5 hasta el final
    std::cout << "Truncated string: " << truncated << std::endl;

    return 0;
}
