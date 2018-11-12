#pragma once

typedef struct {
	int day, month, year;
} DATE;

typedef struct {
	char* name;
	char* supplier;
	int quantity;
	DATE expirationDate;
} Material;

Material* createMaterial(char* name, char* supplier, int quantity, DATE date);
void destroyMaterial(Material* m); //to free the memory
Material* copyMaterial(Material* m);

char* getName(Material* m);
char* getSupplier(Material* m);
int getQty(Material* m);
DATE getExprDate(Material* m);

void toString(Material* m);