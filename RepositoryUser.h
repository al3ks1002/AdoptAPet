//
// Created by alex on 04.04.2016.
//

#ifndef ADOPTAPET_REPOSITORYUSER_H
#define ADOPTAPET_REPOSITORYUSER_H


#include "Playlist.h"
#include "AdoptionList.h"

class RepositoryUser {
public:
    /**
     * Default constructor for RepositoryUser.
     */
    RepositoryUser(AdoptionList* adoption_list);

    /**
     * Sets the list that contains the available dogs.
     * Input: dogs - Vector<Dog>
     */
    void set_list(const std::vector<Dog>& dogs);

    /**
     * Gets the size of the available dogs list.
     */
    int get_size_list();

    /**
     * Gets the current dog from the available dogs list.
     */
    Dog get_current();

    /**
     * Goes to the next dog in the available dogs list.
     */
    void go_next();

    /**
     * Removes the current dog from the available dogs list.
     */
    void remove_current();

    /**
     * Adds a dog in the adoption list.
     * Input: dog - Dog;
     */
    void add_adoption(const Dog& dog);

    /**
     * Returns the list of adopted dogs.
     * Return: dogs - Vector<Dog>
     */
    std::vector<Dog> get_adopted();

    /*
     * Shows the adoption list (csv or html).
     */
    void show_adopted();

private:
    Playlist dog_list;
    AdoptionList* adoption_list;
};


#endif //ADOPTAPET_REPOSITORYUSER_H

