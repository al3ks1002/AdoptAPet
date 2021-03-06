//
// Created by alex on 04.04.2016.
//

#include <algorithm>
#include "ControllerUser.h"

void ControllerUser::set_list() {
    std::vector<Dog> all = this->get_all();
    this->repo_user.set_list(all);
}

std::vector<Dog> ControllerUser::get_all() {
    return this->repo_admin.get_dogs();
}

int ControllerUser::get_size_list() {
    return this->repo_user.get_size_list();
}

Dog ControllerUser::get_current() {
    return this->repo_user.get_current();
}

void ControllerUser::go_next() {
    this->repo_user.go_next();
}

void ControllerUser::adopt(const Dog& dog) {
    this->repo_admin.remove(dog);
    this->repo_user.remove_current();
    this->repo_user.add_adoption(dog);
}

std::vector<Dog> ControllerUser::get_adopted() {
    return this->repo_user.get_adopted();
}

void ControllerUser::set_filtered_list(const std::string& breed, int age) {
    std::vector<Dog> all = this->get_all();
    std::vector<Dog> filtered(all.size());

    auto it = std::copy_if(all.begin(), all.end(), filtered.begin(), [breed, age](Dog dog) {
        return ((dog.get_breed() == breed || breed == "") && dog.get_age() <= age);
    });
    filtered.resize(std::distance(filtered.begin(), it));

    this->repo_user.set_list(filtered);
}

void ControllerUser::show_adopted() {
    this->repo_user.show_adopted();
}







