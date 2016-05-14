//
// Created by alex on 04.04.2016.
//

#include "Playlist.h"


void Playlist::set_available(const Vector<Dog>& dogs) {
    this->available_dogs = dogs;
    this->current = 0;
}

int Playlist::get_size_list() {
    return this->available_dogs.size();
}

Dog Playlist::get_current() {
    return available_dogs[current];
}

void Playlist::go_next() {
    this->current++;
    if (this->current >= this->get_size_list())
        this->current = 0;
}

void Playlist::remove_current() {
    if (this->current == this->available_dogs.size() - 1)
        this->current = 0;

    this->available_dogs.remove(this->current);
}










