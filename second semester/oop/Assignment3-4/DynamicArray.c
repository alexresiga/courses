#include "DynamicArray.h"
#include <stdlib.h>
#include <assert.h>

DynamicArray* createDynamicArray(int capacity, DestroyElementFunctionType destroyElemFct)
{
	DynamicArray* da = (DynamicArray*)malloc(sizeof(DynamicArray));

	if (da == NULL)
		return NULL;

	da->capacity = capacity;
	da->length = 0;

	da->elems = (TElement*)malloc(capacity * sizeof(TElement));
	if (da->elems == NULL)
		return NULL;

	da->destroyElemFct = destroyElemFct;

	return da;
}

void destroy(DynamicArray* arr)
{
	if (arr == NULL)
		return;

	for (int i = 0; i < arr->length; ++i)
		arr->destroyElemFct(arr->elems[i]);

	free(arr->elems);
	arr->elems = NULL;

	free(arr);
	arr = NULL;
}

// Resizes the array, allocating more space.
// If more space cannot be allocated, returns -1, else it returns 0.
int resize(DynamicArray* arr)
{
	if (arr == NULL)
		return -1;

	arr->capacity *= 2;

	TElement* aux = (TElement*)malloc(arr->capacity * sizeof(TElement));
	if (aux == NULL)
		return -1;
	for (int i = 0; i < arr->length; ++i)
	{
		aux[i] = arr->elems[i];
	}
	free(arr->elems);
	arr->elems = aux;

	return 0;
}

void add(DynamicArray* arr, TElement t)
{
	if (arr == NULL)
		return;
	if (arr->elems == NULL)
		return;

	if (arr->length == arr->capacity)
		resize(arr);
	arr->elems[arr->length++] = t;
}

void deleteT(DynamicArray* arr, int pos)
{
	if (arr == NULL)
		return;
	if (arr->elems == NULL)
		return;

	if (pos < 0 || pos >= arr->length)
		return;

	arr->destroyElemFct(arr->elems[pos]);

	for (int i = pos; i < arr->length; ++i)
		arr->elems[i] = arr->elems[i + 1];

	arr->length--;
}

void updateT(DynamicArray* arr, int pos, TElement* t)
{
	if (arr == NULL)
		return;
	if (arr->elems == NULL)
		return;

	if (pos < 0 || pos >= arr->length)
		return;

	arr->elems[pos] = t;
}

int getLength(DynamicArray* arr)
{
	if (arr == NULL)
		return -1;

	return arr->length;
}

TElement get(DynamicArray* arr, int pos)
{
	return arr->elems[pos];
}

// Tests

void testsDynamicArray()
{
	DynamicArray* da = createDynamicArray(2, destroyMaterial);
	if (da == NULL)
		assert(0);

	assert(da->capacity == 2);
	assert(da->length == 0);

	Material* m1 = createMaterial("name1", "supplier1", 123, (DATE) { 4, 3, 2019 });
	add(da, m1);
	assert(da->length == 1);

	Material* m2 = createMaterial("name2", "supplier2", 33, (DATE) { 14, 3, 2019 });
	add(da, m2);
	assert(da->length == 2);

	Material* m3 = createMaterial("name3", "supplier3", 13, (DATE) { 4, 5, 2020 });
	add(da, m3);
	assert(da->length == 3);
	assert(da->capacity == 4);

	Material* m = get(da, 0);
	deleteT(da, 0);

	m = get(da, 0);
	assert(!strcmp(getName(m), "name2"));
	assert(da->length == 2);

	destroy(da);
}