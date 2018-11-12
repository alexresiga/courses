#pragma once
#include "Domain.h"

typedef struct VectorArray {
	Material* array;
	int count;
	int size;
} VectorArray;

int createVector(VectorArray **materialList);
int destroyVector(VectorArray **materialList);

