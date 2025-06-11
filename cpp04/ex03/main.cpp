#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

// int main(void)
// {
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
//     ICharacter* me = new Character("me");
//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);
//     ICharacter* bob = new Character("bob");
//     me->use(0, *bob);
//     me->use(1, *bob);
//     delete bob;
//     delete me;
//     delete src;
//     return 0;
// }

//check again later

int main() {
    std::cout << "===== Creating MateriaSource =====" << std::endl;
    IMateriaSource* src = new MateriaSource();

    std::cout << "\n===== Learning Materias =====" << std::endl;
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "\n===== Creating Character =====" << std::endl;
    ICharacter* me = new Character("Me");

    std::cout << "\n===== Creating Materias from Source =====" << std::endl;
    AMateria* tmp1 = src->createMateria("ice");
    AMateria* tmp2 = src->createMateria("cure");

    std::cout << "\n===== Equipping Materias =====" << std::endl;
    me->equip(tmp1);
    me->equip(tmp2);

    std::cout << "\n===== Creating Another Character =====" << std::endl;
    ICharacter* bob = new Character("Bob");

    std::cout << "\n===== Using Materias on Bob =====" << std::endl;
    me->use(0, *bob); // should print ice message
    me->use(1, *bob); // should print cure message

    std::cout << "\n===== Unequipping First Materia =====" << std::endl;
    me->unequip(0);

    std::cout << "\n===== Deep Copy Test =====" << std::endl;
    Character* copy = new Character(*(Character*)me);
    copy->use(1, *bob); // use copied cure
    delete copy;

    std::cout << "\n===== Cleanup =====" << std::endl;
    delete bob;
    delete me;
    delete src;
    return 0;
}