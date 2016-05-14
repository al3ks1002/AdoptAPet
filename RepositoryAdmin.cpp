//
// Created by alex on 21.03.2016.
//

#include "RepositoryAdmin.h"


bool RepositoryAdmin::add(const Dog& dog) {
    if (this->find(dog) >= 0)
        return 0;

    this->dogs.add(dog);
    return 1;
}

int RepositoryAdmin::find(const Dog& dog) {
    return this->dogs.find(dog);
}

bool RepositoryAdmin::remove(const Dog& dog) {
    int position = this->find(dog);
    if (position == -1)
        return 0;

    this->dogs.remove(position);
    return 1;
}

int RepositoryAdmin::update(const Dog& dog, const Dog& new_dog) {
    int position = this->find(dog);
    if (position == -1)
        return -1;

    int found = this->find(new_dog);
    if (found >= 0 && found != position)
        return 0;

    this->dogs.update(position, new_dog);
    return 1;
}

Vector<Dog> RepositoryAdmin::get_dogs() {
    return this->dogs;
}











