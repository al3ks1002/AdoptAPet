//
// Created by alex on 22.03.2016.
//

#ifndef ADOPTAPET_UTILS_H
#define ADOPTAPET_UTILS_H


#include <string>

class Utils {
public:
    static bool valid_number(const std::string& str);

    static int get_int(const std::string& str);
};


#endif //ADOPTAPET_UTILS_H
