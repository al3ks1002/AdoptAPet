//
// Created by alex on 21.03.2016.
//

#ifndef ADOPTAPET_REPOSITORY_H
#define ADOPTAPET_REPOSITORY_H

#include <vector>

#include "Vector.h"
#include "Dog.h"

class RepositoryAdmin {
public:
    /**
     * Default constructor.
     */
    RepositoryAdmin();

    /*
     * Constructor with filename.
     */
    RepositoryAdmin(std::string filename);

    /**
     * Returns the Vector of dogs.
     */
    std::vector<Dog> get_dogs();

    /**
     * Finds a dog in the repository.
     * Input: dog - Dog.
     * Return: the position where the dog was found or the size of the repository if it wasn't found.
     */
    int find(const Dog& dog);

    /**
     * Adds a dog in the repository only if it isn't a duplicate.
     * Input: dog - Dog.
     * Return: throws OperationException if it is a duplicate.
     */
    void add(const Dog& dog);

    /**
     * Removes a dog from the repository only if it is in the repository.
     * Input: dog - Dog.
     * Return: throws OperationException if the dog is not in the repository.
     */
    void remove(const Dog& dog);

    /**
     * Updates a dog from the repository only if the dog is in the repository and if the updated dog is not a duplicate.
     * Input: dog, new_dog - Dog
     * Return: throws OperationException if the dog is not in the repository or if the new dog is a duplicate.
     */
    void update(const Dog& dog, const Dog& new_dog);

private:
    std::vector<Dog> dogs;
    std::string filename;

    void write_to_file();
};


#endif //ADOPTAPET_REPOSITORY_H

