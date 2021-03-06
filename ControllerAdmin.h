//
// Created by alex on 22.03.2016.
//

#ifndef ADOPTAPET_CONTROLLER_H
#define ADOPTAPET_CONTROLLER_H


#include "RepositoryAdmin.h"

class ControllerAdmin {
public:
    /**
     * Constructor.
     */
    ControllerAdmin(RepositoryAdmin& repo) : repository(repo) { }

    /**
     * Adds a dog in the controller_admin if it isn't a duplicate.
     * Input: age - int.
     *        breed, name, photo - string
     * Return: throws OperationException if it wasn't added.
     */
    void add(int age, std::string breed, std::string name, std::string photo);

    /**
     * Deletes a dog if it is in the controller_admin.
     * Input: age - int
     *        breed, name, photo - string
     * Return: throws OperationException if it wasn't removed.
     */
    void remove(int age, std::string breed, std::string name);

    /**
     * Updates a dog from the controller_admin only if the dog is in the controller_admin and if the updated dog is not a duplicate.
     * Input: age, new_age - int.
     *        breed, name, new_breed, new_name, new_photo - string.
     * Return: throws OperationException if it wasn't updated.
     */
    void update(int age, std::string breed, std::string name, int new_age, std::string new_breed, std::string new_name,
                std::string new_photo);

    /**
     * Returns the vector of dogs from the repository.
     */
    std::vector<Dog> get_all();

private:
    RepositoryAdmin& repository;
};


#endif //ADOPTAPET_CONTROLLER_H

