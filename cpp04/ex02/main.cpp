#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main() {
    const int N = 10;
    // Animal animals;
    Animal* animals[N];

    // Half dogs, half cats
    for (int i = 0; i < N; i++) {
        if (i < N / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n-- Sounds --\n";
    for (int i = 0; i < N; i++) {
        animals[i]->makeSound();
    }

    std::cout << "\n-- Deleting animals --\n";
    for (int i = 0; i < N; i++) {
        delete animals[i];
    }

    Brain testBrain;
    Brain copyBrain;

    testBrain = copyBrain;
    std::cout << &testBrain << std::endl;
    std::cout << &copyBrain << std::endl;

    return 0;
}
