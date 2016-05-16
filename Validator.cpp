//
// Created by alex on 16.05.2016.
//

#include <algorithm>
#include "Validator.h"
#include "CustomException.h"

int Validator::valid_number(const std::string& str, int min_value, int max_value) {
    if (!str.empty() && std::find_if(str.begin(), str.end(), [](char c) { return !std::isdigit(c); }) == str.end()) {
        int number = 0;
        for (auto it:str) {
            number = number * 10 + it - '0';
        }

        if (number >= min_value && number <= max_value) {
            return number;
        } else {
            throw DataException("The number is not in range!");
        }
    } else {
        throw DataException("This is not an integer!");
    }
}

std::string Validator::valid_string(const std::string& str) {
    if (str.empty()) {
        throw DataException("The string is empty!");
    }
    return str;
}
