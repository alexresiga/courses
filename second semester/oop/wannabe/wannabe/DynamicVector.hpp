//
//  DynamicVector.hpp
//  wannabe
//
//Created by Alex Resiga on 19/04/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#pragma once

template <typename T>

class DynamicVector
{
private:
    T* elems;
    int size;
    int capacity;
  
public:
    explicit DynamicVector(int capacity=2);
    
    DynamicVector(const DynamicVector& v);
    ~DynamicVector();
    DynamicVector<T>& operator=(const DynamicVector<T>& v);
    T& operator[](const int index) {return this->elems[index];}
    
    void add(const T& e);
    
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
void DynamicVector<T>::resize(double factor)
{
    this->capacity *= static_cast<int>(factor);
    
    T* els = new T[this->capacity];
    for (int i = 0; i < this->size; ++i)
        els[i] = this->elems[i];
    
    delete[] this->elems;
    
    this->elems = els;
}

template <typename T>
void DynamicVector<T>::add(const T &e)
{
    if ( this->size == this->capacity)
        this->resize();
    this->elems[this->size] = e;
    this->size++;
}

