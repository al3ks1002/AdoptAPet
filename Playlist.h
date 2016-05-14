//
// Created by alex on 04.04.2016.
//

#ifndef ADOPTAPET_PLAYLIST_H
#define ADOPTAPET_PLAYLIST_H


#include <vector>
#include "Dog.h"
#include "Vector.h"

class Playlist {
public:
    /**
     * Default constructor for Playlist.
     */
    Playlist() : current(0) { };

    /**
     * Sets the available dogs for adoption.
     * Input: dogs - Vector<Dog>
     */
    void set_available(const std::vector<Dog>& dogs);

    /**
     * Getter for the size of the list.
     */
    int get_size_list();

    /**
     * Getter for the current dog.
     * Return: the current dog - Dog.
     */
    Dog get_current();

    /**
     * Goes to the next dog in the list.
     */
    void go_next();

    /**
     * Removes the current dog from the list.
     */
    void remove_current();

private:
    std::vector<Dog> available_dogs;
    int current;
};


#endif //ADOPTAPET_PLAYLIST_H

