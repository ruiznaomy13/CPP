#include <iostream>
#include <cstring>

struct User {
  char first_name[50]; // Adjust the size based on your requirements
  char last_name[50];
  int age;

  char status[50]; // Adjust the size based on your requirements

  const char* get_status() const {
    return status;
  }

  void set_status(const char* stat) {
    strncpy(status, stat, sizeof(status));
    status[sizeof(status) - 1] = '\0'; // Ensure null-termination
  }
};

int main() {
  User user1;

  std::cout << "First name: ";
  std::cin.getline(user1.first_name, sizeof(user1.first_name));

  std::cout << "Last name: ";
  std::cin.getline(user1.last_name, sizeof(user1.last_name));

  std::cout << "Status: ";
  std::cin.getline(user1.status, sizeof(user1.status));
  user1.set_status(user1.status);

  std::cout << "Age: ";
  std::cin >> user1.age;

  std::cout << "\n\n----------- DATA ---------- \n";
  std::cout << "First name: " << user1.first_name << std::endl;
  std::cout << "Last name: " << user1.last_name << std::endl;
  std::cout << "Status: " << user1.get_status() << std::endl;
  std::cout << "Age: " << user1.age << std::endl;

  return 0;
}

