//
//  DynamicVector.hpp
//  Assignment5-6
//
//  Created by Alex Resiga on 26/03/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//
#pragma once

template <typename T>

class DynamicVector
{
private:
    T * elems;
    int size;
    int capacity;
    
public:
    //default constructor
    explicit DynamicVector(int capacity = 2);
    
    //constructor with parameters
    DynamicVector(const DynamicVector& v);
    ~DynamicVector();
    
    //overloading for attribute operator
    DynamicVector<T>& operator=(const DynamicVector<T>& v);
    
    DynamicVector<T>& operator-(const T& t);
    
    T& operator[](const int index) {return this->elems[index];}
    
    //method for adding element to Dynamic Vector

    void add(const T& e);
    //method for removing element from Dynamic Vector
    void remove(const int& pos);
    
    //method for updating element
    void update(const int& pos, const T& e);
    
    //method for getting vector size
    int getSize() const;
    
    //method for getting iterator through dynamic vector
    T* getAllElems() const;
    
private:
    void resize(double factor = 2);
};

template <typename T>
DynamicVector<T>::DynamicVector(int capacity)
{
    this->size = 0;
    this->capacity = capacity;
    this->elems = new T[capacity];
}

template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector& v)
{
    this->size = v.size;
    this->capacity = v.capacity;
    this->elems = new T[this->capacity];
    for(int i = 0; i < this->size; ++i)
        this->elems[i] = v.elems[i];
}

template <typename T>
DynamicVector<T>::~DynamicVector()
{
    delete[] this->elems;
}

template <typename T>
DynamicVector<T> & DynamicVector<T>::operator=(const DynamicVector<T>& v)
{
    if (this == &v)
        return *this;
    
    this->size = v.size;
    this->capacity = v.capacity;
    
    delete[] this->elems;
    
    this->elems = new T[this->capacity];
    for (int i = 0; i < this->size; ++i)
        this->elems[i] = v.elems[i];
    
    return *this;
}

template <typename T>
DynamicVector<T> & DynamicVector<T>::operator-(const T& v)
{
    for (int i  = 0; i <this->size; ++i)
        if (this->elems[i] == v)
            this->remove(i);
    
    return *this;
}

template <typename T>
void DynamicVector<T>::add(const T& e)
{
    if (this->size == this->capacity)
        this->resize();
    this->elems[this->size] = e;
    this->size++;
}

template <typename T>
void DynamicVector<T>::remove(const int& pos)
{
    if (pos < 0 or pos >= this->size)
        return;
    
    for (int i = pos; i < this->size-1; ++i)
        this->elems[i] = this->elems[i+1];
    
    this->size--;
}

template <typename T>
void DynamicVector<T>::update(const int& pos, const T& t)
{
    if (pos < 0 or pos >= this->size)
        return;
    this->elems[pos] = t;
}

template <typename T>
void DynamicVector<T>::resize(double factor)
{
    this->capacity *= static_cast<int>(factor);
    
    T* els = new T[this->capacity];
    for (int i = 0; i < this->size; ++i)
        els[i] = this->elems[i];
    
    delete[] this->elems;
    this->elems =els;
}

template <typename T>
T* DynamicVector<T>::getAllElems() const
{
    return this->elems;
}

template <typename T>
int DynamicVector<T>::getSize() const
{
    return this->size;
}
