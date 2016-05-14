//
// Created by alex on 20.03.2016.
//

#include "Dog.h"

Dog::Dog() : age(0), breed(""), name(""), photo("") { }

Dog::Dog(int age, std::string breed, std::string name, std::string photo) {
    this->age = age;
    this->breed = breed;
    this->name = name;
    this->photo = photo;
}

