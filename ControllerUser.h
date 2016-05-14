//
// Created by alex on 04.04.2016.
//

#ifndef ADOPTAPET_CONTROLLERUSER_H
#define ADOPTAPET_CONTROLLERUSER_H


#include "RepositoryAdmin.h"
#include "RepositoryUser.h"

class ControllerUser {
public:
    /**
     * Default constructor.
     */
    ControllerUser(RepositoryAdmin& repo_admin, RepositoryUser& repo_user) : repo_admin(repo_admin),
                                                                             repo_user(repo_user) { };

    /**
     * Sets the list of available dogs with all the dogs.
     */
    void set_list();

    /**
     * Gets all the available dogs.
     * Return: dogs - Vector<Dog>
     */
    Vector<Dog> get_all();

    /**
     * Gets the size of the list that contains the available dogs.
     * Return: int - size of the list.
     */
    int get_size_list();

    /**
     * Gets the current dog from the list that contains the available dogs.
     * Return: Dog - the current dog.
     */
    Dog get_current();

    /**
     * Goes to the next dog in the list.
     */
    void go_next();

    /**
     * Adopts a dog.
     * Input: dog - Dog that needs to be adopted.
     */
    void adopt(const Dog& dog);

    /**
     * Gets the adopted dogs list.
     * Return: dogs - Vector<Dog>
     */
    Vector<Dog> get_adopted();

    /**
     * Sets the list of available dogs with filtered dogs by breed and age.
     * Input: breed - string, age - int.
     */
    void set_filtered_list(const std::string& breed, int age);

private:
    RepositoryAdmin& repo_admin;
    RepositoryUser& repo_user;
};


#endif //ADOPTAPET_CONTROLLERUSER_H

