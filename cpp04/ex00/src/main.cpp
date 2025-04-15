#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int main() {
//     const Animal* meta = new Animal();
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();

//     std::cout << j->getType() << " " << std::endl;
//     std::cout << i->getType() << " " << std::endl;

//     i->makeSound(); // Should output "Meow!"
//     j->makeSound(); // Should output "Woof woof!"
//     meta->makeSound(); // Should output "I don't know who am I"

//     delete meta;
//     delete j;
//     delete i;

//     return 0;
// }

int main()
{
    std::cout << "---- Correct Polymorphism ----" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();  // Outputs "Meow"
    j->makeSound();  // Outputs "Woof woof"
    meta->makeSound(); // Outputs "I Don't know who am i"
    
    delete meta;
    delete j;
    delete i;

    std::cout << "\n---- Wrong Polymorphism ----" << std::endl;
    const WrongAnimal* wrong_meta = new WrongAnimal();
    const WrongAnimal* wrong_cat = new WrongCat();
    
    std::cout << wrong_cat->getType() << " " << std::endl;
    wrong_cat->makeSound();  // Outputs "I am not an Animal :)" instead of "gebfwvdacsetbrvdc"
    wrong_meta->makeSound(); // Outputs "I am not an Animal :)"

    delete wrong_meta;
    delete wrong_cat;

    return 0;
}
