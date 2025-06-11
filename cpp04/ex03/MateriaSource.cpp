#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
    for (int i = 0; i < 4; i++)
        _templates[i] = NULL; 
    std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::~MateriaSource(){
    for (int i = 0; i < 4; i++)
    {
        if (_templates[i] != NULL)
        {
            delete _templates[i];
            _templates[i] = NULL;  
        }
    }
    std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other){
    for (int i = 0; i < 4; i++) {
        if (other._templates[i] != NULL)
            _templates[i] = other._templates[i]->clone();
        else
            _templates[i] = NULL;
    }
    std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this == &other)
        return *this;
    for (int i = 0; i < 4; i++)
    {
        if (_templates[i])
            delete _templates[i];
        if (other._templates[i])
            _templates[i] = other._templates[i]->clone();
        else
            _templates[i] = NULL;
    }
    std::cout << "MateriaSource copy assignment operator called" << std::endl;
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (_templates[i] == NULL)
        {
            _templates[i] = m->clone();
            std::cout << "Materia learned at index " << i << "." << std::endl;
            return ;
        }
    }
    std::cout << "_templates is full. Cannot learn Materia." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_templates[i] != NULL && _templates[i]->getType() == type)
        {
            std::cout << "Materia created" << std::endl;
            return _templates[i]->clone();
        }
    }
    std::cout << "Materia type is unknown" << std::endl;
    return 0;
}
