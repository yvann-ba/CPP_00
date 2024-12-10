#include "MateriaSource.hpp"


MateriaSource::MateriaSource() {
    //std::cout << "MateriaSource Default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
    //std::cout << "MateriaSource Copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        if (other.templates[i])
            templates[i] = other.templates[i]->clone();
        else
            templates[i] = NULL;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
    //std::cout << "MateriaSource operator Assignement constructor called" << std::endl;

    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            delete templates[i];
            if (other.templates[i])
                templates[i] = other.templates[i]->clone();
            else
                templates[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    //std::cout << "MateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        delete templates[i];
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m)
        return;
    for (int i = 0; i < 4; i++) {
        if (templates[i] == NULL) {
            templates[i] = m->clone();
            delete m;
            return;
        }
    }
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; i++) {
        if (templates[i] && templates[i]->getType() == type) {
            return templates[i]->clone();
        }
    }
    return NULL;
}