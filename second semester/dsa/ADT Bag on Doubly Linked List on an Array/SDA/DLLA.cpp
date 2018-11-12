 //
//  DLLA.cpp
//  SDA
//
//  Created by Alex Resiga on 04/06/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#include "DLLA.hpp"

Bag::Bag()
{
    this->capacity = INIT_CAPACITY;
    bag[1].prev = -1;
    bag[1].next = 2;
    bag[INIT_CAPACITY - 1].next = -1;
    bag[INIT_CAPACITY - 1].prev = INIT_CAPACITY - 2;
    for (int i = 1; i < INIT_CAPACITY - 1; ++i)
    {
        bag[i].next = i + 1;
        bag[i].prev = i - 1;
    }
    this->head = -1;
    this->tail = -1;
    this->firstEmpty = 1;
}


void Bag::add(const Product& p)
{
    int newElem = this->firstEmpty;
    this->firstEmpty = this->bag[firstEmpty].next;
    this->bag[newElem].info = p;
    
    
    if (newElem == 1)
    {
        if (this->head == -1)
        {
            this->head = newElem;
            this->tail = newElem;
            
        }
        else
        {
            
            this->bag[this->head].prev = newElem;
            
        }
    }
    else
    {
        int nodC = this->head;
        int pos = 1;
        while (this->bag[nodC].next != this->bag[this->firstEmpty].next)
        {
            pos++;
            nodC = this->bag[nodC].next;
        }
        nodC = this->bag[nodC].prev;
        pos--;
        if (nodC != this->firstEmpty)
        {
            int nodNext = this->bag[nodC].next;
            this->bag[newElem].next = nodNext;
            this->bag[newElem].prev = nodC - 1;
            this->bag[nodC - 1].next = newElem;
            if (nodNext != this->bag[this->firstEmpty].next)
                this->tail = newElem;
            else
                this->bag[nodNext].prev = newElem;
        }
    }
}

bool Bag::search(Product p)
{
    int current = this->head;
    if (current == -1) return false;
    while (current != this->firstEmpty and this->bag[current].info.getID() != p.getID())
        current = this->bag[current].next;
    
    if (current != this->firstEmpty)
        return true;
    return false;
}

void Bag::remove(Product p)
{
    if (this->search(p))
    {
        int nodC = this->head;
        
        int prevNode = -1;
        while (nodC != this->bag[this->firstEmpty].next and this->bag[nodC].info.getID() != p.getID())
        {
            prevNode = nodC;
            nodC = this->bag[nodC].next;
        }
        if (nodC != this->firstEmpty)
        {
            if (nodC == this->head)
            {
                if (this->head == this->tail)
                {
                    this->head = -1;
                    this->tail = -1;
                    this->firstEmpty = 1;
                }
                else
                {
                    this->firstEmpty = this->head;
                    this->head = this->bag[this->head].next;
                    this->bag[this->firstEmpty].next = this->bag[this->tail].next;
                    
                    
                    this->bag[this->tail].next = firstEmpty;
                    
                }
            }
            else
            {
                this->firstEmpty = nodC;
                
                if (nodC == tail)
                    this->tail = prevNode;
                else
                {
                    this->bag[prevNode].next = this->bag[nodC].next;
                    this->bag[this->bag[nodC].next].prev = this->bag[nodC].prev;
                    this->bag[this->bag[nodC].next].next = this->firstEmpty;
                    
                }
                
            }
        }
        
    }
    else return;
}
