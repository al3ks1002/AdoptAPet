//
// Created by alex on 04.04.2016.
//

#include <vector>
#include "RepositoryUser.h"

RepositoryUser::RepositoryUser(AdoptionList* adoption_list) {
    this->adoption_list = adoption_list;
}

void RepositoryUser::set_list(const std::vector<Dog>& dogs) {
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
    this->adoption_list->add(dog);
}

std::vector<Dog> RepositoryUser::get_adopted() {
    return this->adoption_list->get_dogs();
}

void RepositoryUser::show_adopted() {
    this->adoption_list->show_adopted();
}




