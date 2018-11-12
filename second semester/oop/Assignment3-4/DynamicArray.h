 #pragma once
#include "Material.h"
#define CAPACITY 10

typedef void* TElement;
typedef void(*DestroyElementFunctionType)(void*);

typedef struct
{
	TElement* elems;
	int length;
	int capacity; 
	DestroyElementFunctionType destroyElemFct;
} DynamicArray;


/// <summary>
/// Creates a dynamic array of generic elements, with a given capacity.
/// </summary>
/// <param name="capacity">Integer, maximum capacity for the dynamic array.</param>
/// <returns>A pointer the the created dynamic array.</returns>
DynamicArray* createDynamicArray(int capacity, DestroyElementFunctionType destroyElemFct);

/*
	fres memory allocated for dynamic array
*/
void destroy(DynamicArray*);
/*
	function that resizes dynamic array if length > capacity and doubles capacity
*/
int resize(DynamicArray*);

/*
	adds a generic element to a dynamic array
	input: dynamic array and an element
*/
void add(DynamicArray*, TElement);

/*
	deletes element from dynamic array if it exists
	input: dynamic array and int position of element to be deleted
*/
void deleteT(DynamicArray*, int);

/*
	function that gets element from specific position of dynamic array
	output: Telement
*/
TElement get(DynamicArray*, int);

/*
	function that updates an element froma given position with a new one
	input: dynamic array, int position, TElement* new material
	output: none
*/
void updateT(DynamicArray*, int, TElement*);

/*
	return length of dynamic array
	input: dynamic array
	output: int number of elements
*/
int getLength(DynamicArray*);

void testsDynamicArray();