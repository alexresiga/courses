//
//  DLLA.hpp
//  SDA
//
//  Created by Alex Resiga on 04/06/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#pragma once
#define INIT_CAPACITY 100
#include "Product.hpp"
#include <assert.h>
#include <iostream>

struct DLLANode
{
    Product info;
    int next, prev;
};


class Bag
{
private:
    DLLANode bag[INIT_CAPACITY];
    int capacity;
    int head;
    int tail;
    int firstEmpty;
    
public:
    Bag();
    
    friend class DLLAIterator;
    
    friend class Tests;
    
    void add(const Product& p);
    
    bool search(Product p);
    
    void remove(Product p);
};



class DLLAIterator
{
private:
    Bag list;
    int currentElement;
    
public:
    DLLAIterator() {}
    friend class Tests;
    DLLAIterator(Bag b) : list{ b }, currentElement{ b.tail } {}
    
    auto isEmpty() { return this->currentElement == -1 or this->currentElement == list.firstEmpty; }
    
    auto getCurrent() { return this->list.bag[this->currentElement].info; }
    
    void next() { this->currentElement = this->list.bag[this->currentElement].prev; }
    
    bool valid() { return this->currentElement != 0; }
    
};



class Tests
{
    
public:
    void all()
    {
        Bag bag{};
        Product p1{ 1, "car", "nice description" };
        Product p2{ 2, "house", "another description" };
        Product p3{ 3, "lorem", "ipsum" };
        bag.add(p1);
        assert(bag.search(p1) == true);
        assert(bag.firstEmpty == 2);
        assert(bag.head == 1);
        assert(bag.search(p2) == false);
        bag.add(p2);
        assert(bag.tail == 2);
        assert(bag.firstEmpty == 3);
        bag.remove(p2);
        assert(bag.firstEmpty == 2);
        bag.remove(p1);
        assert(bag.tail == -1);
        assert(bag.head == -1);
        bag.remove(p3);
        assert(bag.firstEmpty == 1);
        bag.add(p1);
        bag.add(p2);
        DLLAIterator it{ bag };
        assert(it.getCurrent().getID() == p1.getID());
        it.next();
        assert(it.getCurrent().getID() == p2.getID());
        it.next();
        assert(it.valid() == false);
    }
};
