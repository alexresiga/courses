#define _CRT_SECURE_NO_WARNINGS
#include "Material.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Material* createMaterial(char* name, char* supplier, int qty, DATE date)
{	
	/*
		creates a struct element of type Material
		input: char name, supplier; int quantity; time: date;
		output: m: Material having the aforementioned atributes
	*/
	Material* m = (Material*)malloc(sizeof(Material));
	m->name = (char*)malloc(sizeof(char)* (strlen(name) + 1));
	strcpy(m->name, name);

	m->supplier = (char*)malloc(sizeof(char) *(strlen(supplier) + 1));
	strcpy(m->supplier, supplier);
	m->quantity = qty;
	m->expirationDate = date;

	return m;
}

void destroyMaterial(Material*  m)
{
	if (m == NULL)
		return;
	
	free(m->name);
	free(m->supplier);

	free(m);
}

Material* copyMaterial(Material* m)
{
	if (m == NULL)
		return NULL;
	
	Material* newMaterial = createMaterial(getName(m), getSupplier(m), getQty(m), getExprDate(m));

	return newMaterial;
}

char* getName(Material* m)
{
	return m->name;
}

char* getSupplier(Material* m)
{
	return m->supplier;
}

int getQty(Material* m)
{
	return m->quantity;
}

DATE getExprDate(Material* m)
{
	return m->expirationDate;
}

void toString(Material* m)
{
	//printf("sper ca ajunge pana aici");
    printf("Material %s:\n\t-supplied by: %s\n\t-quantity: %d\n\t-expiration date: %d.%d.%d\n\n\n", m->name, m->supplier, m->quantity, m->expirationDate.day, m->expirationDate.month, m->expirationDate.year);
}
