//
// Created by alex on 21.03.2016.
//

#ifndef ADOPTAPET_REPOSITORY_H
#define ADOPTAPET_REPOSITORY_H


#include "Vector.h"
#include "Dog.h"

class RepositoryAdmin {
public:
    /**
     * Constructor.
     */
    RepositoryAdmin() { };

    /**
     * Returns the Vector of dogs.
     */
    Vector<Dog> get_dogs();

    /**
     * Finds a dog in the repository.
     * Input: dog - Dog.
     * Return: the position where the dog was found or -1 if it wasn't found.
     */
    int find(const Dog& dog);

    /**
     * Adds a dog in the repository only if it isn't a duplicate.
     * Input: dog - Dog.
     * Return: True if it was added, False otherwise.
     */
    bool add(const Dog& dog);

    /**
     * Removes a dog from the repository only if it is in the repository.
     * Input: dog - Dog.
     * Return: True if it was deleted, False otherwise.
     */
    bool remove(const Dog& dog);

    /**
     * Updates a dog from the repository only if the dog is in the repository and if the updated dog is not a duplicate.
     * Input: dog, new_dog - Dog
     * Return: -1 - if dog isn't in the repository.
     *          0 - if new_dog is a duplicate.
     *          1 - if it was updated.
     */
    int update(const Dog& dog, const Dog& new_dog);

private:
    Vector<Dog> dogs;
};


#endif //ADOPTAPET_REPOSITORY_H

