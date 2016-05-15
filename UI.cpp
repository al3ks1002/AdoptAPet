//
// Created by alex on 22.03.2016.
//

#include "UI.h"
#include "Utils.h"

#include <iostream>

void UI::print_menu() {
    std::cout << '\n';
    std::cout << "---General menu---\n";
    std::cout << "1. Admin mode.\n";
    std::cout << "2. User mode.\n";
    std::cout << "0. Exit.\n";
}

void UI::print_admin_menu() {
    std::cout << '\n';
    std::cout << "---Administrator menu---\n";
    std::cout << "1. Add a dog.\n";
    std::cout << "2. Delete a dog.\n";
    std::cout << "3. Update a dog.\n";
    std::cout << "4. See all dogs.\n";
    std::cout << "0. Back.\n";
}

void UI::print_user_menu() {
    std::cout << '\n';
    std::cout << "---User menu---\n";
    std::cout << "1. See all the dogs in the database.\n";
    std::cout << "2. See all the dogs of a given breed, having age less than a given number.\n";
    std::cout << "3. See adoption list.\n";
    std::cout << "0. Back.\n";
}

void UI::print_playlist_menu() {
    std::cout << '\n';
    std::cout << "---Dogs menu---\n";
    std::cout << "1. Adopt this dog.\n";
    std::cout << "2. See the next dog.\n";
    std::cout << "0. Back.\n";
}

int UI::read_integer(const std::string& message, int min_value, int max_value) {
    std::string number_str;
    while (1) {
        std::cout << message;
        std::getline(std::cin, number_str);

        int number = 0;
        if (Utils::valid_number(number_str)) {
            number = Utils::get_int(number_str);
            if (number >= min_value && number <= max_value)
                return number;
            std::cout << "The integer is not in range!\n";
        } else
            std::cout << "That's not an integer!\n";
    }
}

std::string UI::read_string(const std::string& message) {
    std::cout << message;
    std::string str;
    std::getline(std::cin, str);
    return str;
}

void UI::run_UI() {
    bool good = 1;
    while (good) {
        print_menu();
        int command = read_integer("Enter a command: ", 0, 2);

        switch (command) {
            case 0:
                std::cout << "Bye!\n";
                good = 0;
                break;
            case 1:
                this->run_admin();
                break;
            case 2:
                this->run_user();
                break;
            default:
                std::cout << "Invalid command!\n";
        }
    }
}

void UI::run_admin() {
    bool good = 1;
    while (good) {
        print_admin_menu();
        int command = read_integer("Enter a command: ", 0, 4);

        switch (command) {
            case 0:
                good = 0;
                break;
            case 1:
                this->add();
                break;
            case 2:
                this->remove();
                break;
            case 3:
                this->update();
                break;
            case 4:
                this->show_all();
                break;
            default:
                std::cout << "Invalid command!\n";
        }
    }
}

void UI::run_user() {
    bool good = 1;
    while (good) {
        print_user_menu();
        int command = read_integer("Enter a command: ", 0, 3);

        switch (command) {
            case 0:
                good = 0;
                break;
            case 1:
                this->see_all();
                break;
            case 2:
                this->see_filtered();
                break;
            case 3:
                this->see_adopted();
                break;
            default:
                std::cout << "Invalid command!\n";
        }
    }
}

void UI::add() {
    std::string breed = read_string("Enter the breed: ");
    std::string name = read_string("Enter the name: ");
    int age = read_integer("Enter the age: ", 0, 100);
    std::string photo = read_string("Enter the link to the photo: ");

    bool added = this->controller_admin.add(age, breed, name, photo);
    if (added)
        std::cout << "Added successfully!\n";
    else
        std::cout << "Duplicate dog!\n";
}

void UI::remove() {
    std::string breed = read_string("Enter the breed: ");
    std::string name = read_string("Enter the name: ");
    int age = read_integer("Enter the age: ", 0, 100);

    bool removed = this->controller_admin.remove(age, breed, name);
    if (removed)
        std::cout << "Deleted successfully!\n";
    else
        std::cout << "Can't find the dog!\n";
}

void UI::update() {
    std::string breed = read_string("Enter the breed: ");
    std::string name = read_string("Enter the name: ");
    int age = read_integer("Enter the age: ", 0, 100);

    std::string new_breed = read_string("Enter the breed: ");
    std::string new_name = read_string("Enter the name: ");
    int new_age = read_integer("Enter the age: ", 0, 100);
    std::string new_photo = read_string("Enter the link to the photo: ");

    int updated = this->controller_admin.update(age, breed, name, new_age, new_breed, new_name, new_photo);
    if (updated == -1)
        std::cout << "Can't find the dog!\n";
    else if (updated == 0)
        std::cout << "Duplicate dog!\n";
    else
        std::cout << "Updated successfully!\n";
}

void UI::show_all() {
    std::vector<Dog> dogs = this->controller_admin.get_all();
    if (dogs.size() == 0)
        std::cout << "There aren't any dogs!\n";
    else {
        for (auto dog : dogs) {
            std::cout << dog << '\n';
        }
    }
}

void UI::see_all() {
    this->controller_user.set_list();
    this->run_playlist();
}

void UI::see_filtered() {
    std::string breed = read_string("Enter the breed: ");
    int age = read_integer("Enter the maximum age: ", 0, 100);
    this->controller_user.set_filtered_list(breed, age);
    this->run_playlist();
}

void UI::see_adopted() {
    std::vector<Dog> adopted = this->controller_user.get_adopted();
    if (adopted.size() == 0)
        std::cout << "There aren't any dogs!\n";
    else {
        for (auto dog : adopted) {
            std::cout << dog << '\n';
        }
    }
}

void UI::run_playlist() {
    bool good = 1;
    while (good) {
        if (this->controller_user.get_size_list() == 0) {
            std::cout << "There aren't any dogs!\n";
            break;
        }

        Dog current_dog = this->controller_user.get_current();
        std::cout << '\n' << current_dog.get_breed() << " | " << current_dog.get_name() << " | " <<
        current_dog.get_age() << '\n';

        std::string shell = "xdg-open ";
        shell += current_dog.get_photo();
        shell += " > /dev/null";
        system(shell.c_str());

        bool cycle = 1;
        while (cycle) {
            this->print_playlist_menu();
            int command = read_integer("Enter a command: ", 0, 2);

            switch (command) {
                case 0:
                    cycle = 0;
                    good = 0;
                    break;
                case 1:
                    cycle = 0;
                    this->controller_user.adopt(current_dog);
                    break;
                case 2:
                    this->controller_user.go_next();
                    cycle = 0;
                    break;
                default:
                    std::cout << "Invalid command!\n";
            }
        }
    }
}




