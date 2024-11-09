#include <iostream>
#include <map>

int main() {
    std::multimap<int, std::string> people;
    people.insert(std::make_pair(1, "Alice"));
    people.insert(std::make_pair(1, "Anna")); // duplicate key allowed

    for (std::multimap<int, std::string>::iterator it = people.begin(); it != people.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
    return 0;
}
