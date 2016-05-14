//
// Created by alex on 21.03.2016.
//

#include <algorithm>
#include "RepositoryAdmin.h"


bool RepositoryAdmin::add(const Dog& dog) {
    if (this->find(dog) < this->dogs.size())
        return 0;

    this->dogs.push_back(dog);
    return 1;
}

int RepositoryAdmin::find(const Dog& dog) {
    auto it = std::find(this->dogs.begin(), this->dogs.end(), dog);
    return it - this->dogs.begin();
}

bool RepositoryAdmin::remove(const Dog& dog) {
    int position = this->find(dog);
    if (position == this->dogs.size())
        return 0;

    this->dogs.erase(this->dogs.begin() + position);
    return 1;
}

int RepositoryAdmin::update(const Dog& dog, const Dog& new_dog) {
    int position = this->find(dog);
    if (position == this->dogs.size())
        return -1;

    int new_position = this->find(new_dog);
    if (new_position != this->dogs.size() && new_position != position)
        return 0;

    this->dogs[position] = new_dog;
    return 1;
}

std::vector<Dog> RepositoryAdmin::get_dogs() {
    return this->dogs;
}











