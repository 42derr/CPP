#include "Character.hpp"

Character::Character(): name("default"), droppedCount(0){
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL; 
    for (int j = 0; j < 100; j++)
        dropped[j] = NULL; 
    std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string name): name(name), droppedCount(0){
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL; 
    for (int j = 0; j < 100; j++)
        dropped[j] = NULL; 
    std::cout << "Character constructor called" << std::endl;
}

Character::~Character() {
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] != NULL) {
            delete inventory[i];
            inventory[i] = NULL;
        }
    }
    for (int j = 0; j < droppedCount; j++)
    {
        if (dropped[j] != NULL) {
            delete dropped[j];
            dropped[j] = NULL;
        }
    }
    std::cout << "Character destructor called" << std::endl;
}

Character::Character(const Character& other) : name(other.name), droppedCount(0) {
    for (int i = 0; i < 4; i++) {
        if (other.inventory[i] != NULL)
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
    for (int j = 0; j < 100; j++) {
        dropped[j] = NULL;
    }
    std::cout << "Character copy constructor called" << std::endl;
}

Character& Character::operator=(const Character& other) {
    if (this == &other)
        return *this;
    this->name = other.getName();
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i])
            delete inventory[i];
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
    for (int i = 0; i < droppedCount; i++) {
        if (dropped[i]) {
            delete dropped[i];
            dropped[i] = NULL;
        }
    }
    droppedCount = 0;
    std::cout << "Character copy assignment operator called" << std::endl;
    return *this;
}

std::string const & Character::getName() const{
    return this->name;
}


void Character::equip(AMateria* m){
    if (!m)
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] == NULL)
        {
            inventory[i] = m;
            std::cout << "Materia equipped at index " << i << "." << std::endl;
            return ;
        }
    }
    std::cout << "Inventory is full. Cannot equip Materia." << std::endl;
}

void Character::unequip(int idx){
    if (idx < 0 || idx >= 4)
    {
        std::cout << "Invalid index for unequip: " << idx << "." << std::endl;
        return ;
    }
    if (inventory[idx] == NULL)
    {
        std::cout << "Cannot unequip: inventory slot " << idx << " is empty." << std::endl;
        return ;
    }
    if (droppedCount >= 100) {
        std::cout << "Dropped list full, you can't unequip materia" << std::endl;
        return ;
    } 
    else {
        dropped[droppedCount++] = inventory[idx];
        std::cout << "Materia moved to dropped list." << std::endl;
    }
    inventory[idx] = NULL;
    std::cout << "Materia unequipped" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4)
    {
        std::cout << "Can't use: Invalid index" << std::endl;
        return ;
    }
    if (inventory[idx] == NULL)
    {
        std::cout << "Can't use: the inventory slot is empty at this index." << std::endl;
        return ;
    }
    inventory[idx]->use(target);
}
