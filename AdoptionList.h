//
// Created by alex on 16.05.2016.
//

#ifndef ADOPTAPET_ADOPTIONLIST_H
#define ADOPTAPET_ADOPTIONLIST_H


#include <string>
#include <vector>
#include "Dog.h"

class AdoptionList {
public:
    AdoptionList() { }

    AdoptionList(std::string filename = "") : filename(filename) { }

    void add(const Dog& dog);

    std::vector<Dog> get_dogs();

    virtual void show_adopted() = 0;

protected:
    std::string filename;
    std::vector<Dog> dogs;

    virtual void write_to_file() = 0;
};

class CSVAdoptionList : public AdoptionList {
public:

    CSVAdoptionList(std::string filename) : AdoptionList(filename) { }

    void show_adopted() override;

private:
    void write_to_file() override;
};

class HTMLAdoptionList : public AdoptionList {
public:

    HTMLAdoptionList(std::string filename) : AdoptionList(filename) { }

    void show_adopted() override;

private:
    void write_to_file() override;
};

#endif //ADOPTAPET_ADOPTIONLIST_H
