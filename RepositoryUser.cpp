//
// Created by alex on 04.04.2016.
//

#include "RepositoryUser.h"

void RepositoryUser::set_list(const Vector<Dog>& dogs) {
    this->dog_list.set_available(dogs);
}

int RepositoryUser::get_size_list() {
    return this->dog_list.get_size_list();
}

Dog RepositoryUser::get_current() {
    return this->dog_list.get_current();
}

void RepositoryUser::go_next() {
    this->dog_list.go_next();
}

void RepositoryUser::remove_current() {
    this->dog_list.remove_current();
}

void RepositoryUser::add_adoption(const Dog& dog) {
    this->adoption_list.add(dog);
}

Vector<Dog> RepositoryUser::get_adopted() {
    return this->adoption_list;
}


