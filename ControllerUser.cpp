//
// Created by alex on 04.04.2016.
//

#include "ControllerUser.h"

void ControllerUser::set_list() {
    Vector<Dog> all = this->get_all();
    this->repo_user.set_list(all);
}

Vector<Dog> ControllerUser::get_all() {
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

Vector<Dog> ControllerUser::get_adopted() {
    return this->repo_user.get_adopted();
}

void ControllerUser::set_filtered_list(const std::string& breed, int age) {
    Vector<Dog> all = this->get_all();
    Vector<Dog> filtered{};

    for (int i = 0; i < all.size(); i++)
        if ((all[i].get_breed() == breed || breed == "") && all[i].get_age() <= age)
            filtered.add(all[i]);

    this->repo_user.set_list(filtered);
}








