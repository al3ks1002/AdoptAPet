//
// Created by alex on 15.05.2016.
//

#ifndef ADOPTAPET_CUSTOMEXCEPTION_H
#define ADOPTAPET_CUSTOMEXCEPTION_H


#include <exception>
#include <string>

class CustomException : public std::exception {
public:
    CustomException(std::string message = "") : message{message} { }

    virtual const char* what() const throw() {
        return this->message.c_str();
    }

private:
    std::string message;
};

class DataException : public CustomException {
public:
    DataException(std::string message = "") : CustomException{message} { }
};

class OperationException : public CustomException {
public:
    OperationException(std::string message = "") : CustomException{message} { }
};

#endif //ADOPTAPET_CUSTOMEXCEPTION_H
