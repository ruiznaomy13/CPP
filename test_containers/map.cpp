#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> people;
    people[1] = "Alice";
    people[2] = "Bob";

    for (std::map<int, std::string>::iterator it = people.begin(); it != people.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
    return 0;
}
