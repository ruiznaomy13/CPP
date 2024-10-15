#include <iostream>
#include <string>

// Base class Animal
class Animal
{
	protected:
		std::string name;

	public:
		Animal(const std::string& name) : name(name) {}
		virtual ~Animal() {}

		virtual void makeSound() const = 0;  // Pure virtual function
};

// Derived class Dog
class Dog : public Animal
{
	public:
		Dog() : Animal("Dog") {}
		void makeSound() const {
			std::cout << "Woof! Woof!" << std::endl;
		}
};

// Derived class Cat
class Cat : public Animal
{
	public:
		Cat() : Animal("Cat") {}
		void makeSound() const {
			std::cout << "Meow! Meow!" << std::endl;
		}
};

// Derived class Rabbit
class Rabbit : public Animal
{
	public:
		Rabbit() : Animal("Rabbit") {}
		void makeSound() const {
			std::cout << "Squeak! Squeak!" << std::endl;
		}
};


// A struct to hold the animal type string and corresponding constructor function
struct AnimalEntry
{
    const char* animalType;
    Animal* (*createFunction)();
};

class Adoption {
private:
    // Non-static array of known animals and their corresponding constructor functions
    AnimalEntry animalEntries[4];

    // Function prototypes for creating specific animals
    static Animal* createDog() {
        return new Dog();
    }

    static Animal* createCat() {
        return new Cat();
    }

    static Animal* createRabbit() {
        return new Rabbit();
    }

public:
    // Constructor to initialize the lookup table
    Adoption() {
        animalEntries[0] = AnimalEntry{"dog", createDog};
        animalEntries[1] = AnimalEntry{"cat", createCat};
        animalEntries[2] = AnimalEntry{"rabbit", createRabbit};
        animalEntries[3] = AnimalEntry{0, 0};  // Sentinel entry to mark the end of the array
    }

    Animal* adoptAnimal(const std::string& animalName) {
        // Loop through the animal entries to find a match
        for (int i = 0; animalEntries[i].animalType != 0; ++i) {
            if (animalName == animalEntries[i].animalType)
                return animalEntries[i].createFunction();
        }
        std::cerr << "Unknown animal type: " << animalName << std::endl;
        return 0;  // Return NULL if the animal type is not found
    }
};

int main() {
    Adoption adoptionCenter;

    // Example: Adopt a dog
    Animal* adoptedAnimal = adoptionCenter.adoptAnimal("dog");

    if (adoptedAnimal) {
        adoptedAnimal->makeSound();
        delete adoptedAnimal;  // Don't forget to delete the dynamically allocated object
    }

    // Example: Try to adopt an unknown animal
    adoptedAnimal = adoptionCenter.adoptAnimal("lion");
    if (adoptedAnimal) {
        delete adoptedAnimal;  // Clean up in case of successful adoption
    }

    return 0;
}
