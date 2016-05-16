//
// Created by alex on 16.05.2016.
//

#ifndef ADOPTAPET_VALIDATOR_H
#define ADOPTAPET_VALIDATOR_H


#include <string>

class Validator {
public:
    /*
     * Validates a number (contains only digits and it is in the given range).
     * Input: a string and a range of integers.
     * Output: an int representing the number if the number is valid, throws DataException otherwise.
     */
    static int valid_number(const std::string& str, int min_value, int max_value);

    /*
     * Validates a string (checks if it is empty or not).
     * Input: a string.
     * Output: a string representing the original string if it is valid, throws DataException otherwise.
     */
    static std::string valid_string(const std::string& str);
};


#endif //ADOPTAPET_VALIDATOR_H
