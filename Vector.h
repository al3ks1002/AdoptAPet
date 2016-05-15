//
// Created by alex on 20.03.2016.
//

#ifndef ADOPTAPET_VECTOR_H
#define ADOPTAPET_VECTOR_H

#include <ctime>
#include "Dog.h"

template<typename T>
class Vector {
public:
    /**
     * Default constructor.
     */
    Vector(int capacity = 10);

    /**
     * Copy constructor.
     */
    Vector(const Vector<T>& that);

    /**
     * Destructor.
     */
    ~Vector();

    /**
     * Operator overload for [].
     */
    T& operator[](int pos);

    /**
     * Operator overload for =.
     */
    Vector<T>& operator=(const Vector<T>& that);

    /**
     * Adds an element in vector.
     * Input: elem - T
     */
    void add(const T& elem);

    /**
     * Checks if an element is in vector.
     * Input: elem - T
     * Return: the position in the vector or -1 if it isn't find.
     */
    int find(const T& elem);

    /**
     * Removes an element from a given position.
     * Input: position - int.
     */
    void remove(int position);

    /**
     * Updates an element from a given position.
     * Input: position - int.
     *        new_dog - Dog.
     */
    void update(int position, const T& new_elem);

    /**
     * Returns the size of the vector.
     * Return: sz - int.
     */
    int size();

private:
    T* list;
    int sz;
    int capacity;

    void resize();
};

template<typename T>
Vector<T>::Vector(int capacity) {
    this->sz = 0;
    this->capacity = capacity;
    this->list = new T[capacity];
}

template<typename T>
Vector<T>::Vector(const Vector& that) {
    this->sz = that.sz;
    this->capacity = that.capacity;
    this->list = new T[this->capacity];
    for (int i = 0; i < this->sz; i++)
        this->list[i] = that.list[i];
}

template<typename T>
Vector<T>::~Vector() {
    delete[] this->list;
}

template<typename T>
T& Vector<T>::operator[](int pos) {
    return this->list[pos];
}

template<typename T>
void Vector<T>::add(const T& elem) {
    if (this->sz == this->capacity)
        this->resize();

    this->list[this->sz++] = elem;
}

template<typename T>
int Vector<T>::find(const T& elem) {
    for (int i = 0; i < this->sz; i++)
        if (this->list[i] == elem)
            return i;
    return -1;
}

template<typename T>
void Vector<T>::remove(int position) {
    for (int i = position; i < this->size() - 1; i++)
        this->list[i] = this->list[i + 1];

    this->sz--;
}

template<typename T>
void Vector<T>::update(int position, const T& new_elem) {
    this->list[position] = new_elem;
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& that) {
    if (this == &that) {
        return *this;
    }

    this->sz = that.sz;
    this->capacity = that.capacity;

    delete[] this->list;
    this->list = new T[this->capacity];
    for (int i = 0; i < this->sz; i++)
        this->list[i] = that.list[i];

    return *this;
}

template<typename T>
void Vector<T>::resize() {
    this->capacity *= 2;

    T* aux = new T[this->capacity];
    for (int i = 0; i < this->sz; i++)
        aux[i] = this->list[i];

    delete[] this->list;
    this->list = aux;
}

template<typename T>
int Vector<T>::size() {
    return this->sz;
}


#endif //ADOPTAPET_VECTOR_H

