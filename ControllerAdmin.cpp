//
// Created by alex on 22.03.2016.
//

#include "ControllerAdmin.h"

void ControllerAdmin::add(int age, std::string breed, std::string name, std::string photo) {
    Dog dog{age, breed, name, photo};
    this->repository.add(dog);
}

void ControllerAdmin::remove(int age, std::string breed, std::string name) {
    std::string str = "";
    Dog dog{age, breed, name, str};
    this->repository.remove(dog);
}

void ControllerAdmin::update(int age, std::string breed, std::string name, int new_age, std::string new_breed,
                            std::string new_name, std::string new_photo) {
    std::string str = "";
    Dog dog{age, breed, name, str};
    Dog new_dog{new_age, new_breed, new_name, new_photo};
    this->repository.update(dog, new_dog);
}

std::vector<Dog> ControllerAdmin::get_all() {
    return this->repository.get_dogs();
}







