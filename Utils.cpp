//
// Created by alex on 22.03.2016.
//

#include <algorithm>
#include "Utils.h"

bool Utils::valid_number(const std::string& str) {
    return !str.empty() && std::find_if(str.begin(), str.end(), [](char c) { return !std::isdigit(c); }) == str.end();
}

int Utils::get_int(const std::string& str) {
    int number = 0;
    for (auto it:str)
        number = number * 10 + it - '0';
    return number;
}




