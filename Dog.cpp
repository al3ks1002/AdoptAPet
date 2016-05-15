//
// Created by alex on 20.03.2016.
//

#include <iostream>
#include "Dog.h"
#include "Utils.h"

Dog::Dog() : age(0), breed(""), name(""), photo("") { }

Dog::Dog(int age, std::string breed, std::string name, std::string photo) {
    this->age = age;
    this->breed = breed;
    this->name = name;
    this->photo = photo;
}

std::istream& operator>>(std::istream& stream, Dog& dog) {
    std::string line;
    std::getline(stream, line);

    dog.breed = "";
    dog.name = "";
    dog.photo = "";
    std::string age = "";
    int pipes = 0;

    for (auto it:line) {
        if (it == '|') {
            pipes++;
        } else {
            if (pipes == 0) {
                dog.breed += it;
            } else if (pipes == 1) {
                dog.name += it;
            } else if (pipes == 2) {
                age += it;
            } else {
                dog.photo += it;
            }
        }
    }

    dog.age = Utils::get_int(age);

    return stream;
}

std::ostream& operator<<(std::ostream& stream, const Dog& dog) {
    stream << dog.breed << "|" << dog.name << "|" << dog.age << "|" << dog.photo;
    return stream;
}
