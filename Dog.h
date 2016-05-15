//
// Created by alex on 20.03.2016.
//

#ifndef ADOPTAPET_DOG_H
#define ADOPTAPET_DOG_H

#include <string>

class Dog {
public:
    /**
     * Default constructor.
     */
    Dog();

    /**
     * Constructor.
     */
    Dog(int age, std::string breed, std::string name, std::string photo);

    /**
     * Getter for age.
     */
    int get_age() const {
        return this->age;
    }

    /**
     * Getter for breed.
     */
    std::string get_breed() const {
        return this->breed;
    }

    /**
     * Getter for name.
     */
    std::string get_name() const {
        return this->name;
    }

    /**
     * Getter for photo.
     */
    std::string get_photo() const {
        return this->photo;
    }

    /**
     * Overload for the == operator (is_equal).
     */
    bool operator==(const Dog& that) {
        return this->age == that.get_age() && this->breed == that.get_breed() && this->name == that.get_name();
    }

    /*
     * Overload for the >> operator.
     */
    friend std::istream& operator>>(std::istream& stream, Dog& dog);

    /*
     * Overload for the << operator.
     */
    friend std::ostream& operator<<(std::ostream& stream, const Dog& dog);

private:
    int age;
    std::string breed;
    std::string name;
    std::string photo;
};

#endif //ADOPTAPET_DOG_H

