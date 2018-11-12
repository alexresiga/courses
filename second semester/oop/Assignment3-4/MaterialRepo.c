#define _CRT_SECURE_NO_WARNINGS
#include "MaterialRepo.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

MaterialRepo* createRepo()
{
	MaterialRepo* v = (MaterialRepo*)malloc(sizeof(MaterialRepo));
	v->materials = createDynamicArray(CAPACITY, &destroyMaterial);

	return v;
} 

int compareTime(DATE a, DATE b)
{
	if (a.year == b.year)
		if (a.month == b.month)
			if (a.day == b.day)
				return 0;
			else if (a.day < b.day)
				return -1;
			else return 1;
		else if (a.month < b.month)
			return -1;
		else return 1;
	else if (a.year < b.year)
		return -1;
	else return 1;
}

int compareMaterials(Material* a, Material* b)
{
	if (!strcmp(a->name, b->name) && !strcmp(a->supplier, b->supplier) && !compareTime(a->expirationDate, b->expirationDate))
		return 1;

	return -1;

}

void destroyRepo(MaterialRepo* v)
{
	if (v == NULL)
		return;

	
	destroy(v->materials);
	free(v);
}

int find(MaterialRepo* v, Material* m)
{	
	if (v == NULL)
		return -1;

	for (int i = 0; i < getLength(v->materials); ++i)
	{
		if (compareMaterials(get(v->materials, i), m) == 1)
			return i;
	}

	return -1;
}

Material* findByMaterial(MaterialRepo* v, Material* m)
{
	if (v == NULL)
		return NULL;

	int pos = find(v, m);
	if (pos == -1)
		return NULL;
	return get(v->materials, pos);
}

Material* getMaterial(MaterialRepo* v, int index)
{	
	if (v == NULL)
		return NULL;

	if (index < 0 || index >= getLength(v->materials))
		return NULL;

	return get(v->materials, index);
}

int addMaterial(MaterialRepo* v, Material* m)
{
	if (find(v, m) != -1)
	{
		int index = find(v, m);
		findByMaterial(v, m)->quantity += getQty(m);
		
	}
	else {
		Material* copy = copyMaterial(m);
		add(v->materials, copy);
		}
	return 1;
}

int getLengthRepo(MaterialRepo* v)
{
	if (v == NULL)
		return -1;

	return getLength(v->materials);
}

void removeM(MaterialRepo* v, Material* m)
{
	if (v == NULL)
		return ;
	int pos = find(v, m);
	if (pos == -1)
	return;

	//destroyMaterial(m);

	deleteT(v->materials, pos);

}

int updateM(MaterialRepo* v, Material* m)
{
	if (find(v, m) == -1)
		return 0;
	int pos = find(v, m);
	updateT(v->materials, pos, m);
	return 1;
}

//TESTS

void initMaterialRepoForTests(MaterialRepo* v)
{
	DATE d;
	d.day = 12;
	d.month = 9;
	d.year = 2019;
	Material* m = createMaterial("lapte", "zuzu", 123, d);
	addMaterial(v, m);

	destroyMaterial(m);
}

void testAdd()
{
	DATE d1;
	d1.day = 12;
	d1.month = 9;
	d1.year = 2019;
	Material* m = createMaterial("cheese", "doctor_cheese", 123, d1);

	MaterialRepo* v = createRepo();
	initMaterialRepoForTests(v);
	assert(getLengthRepo(v) == 1);

	assert(addMaterial(v, m) == 1);
	assert(getLengthRepo(v) == 2);

	assert(addMaterial(v, m) == 1);
	assert(getLengthRepo(v) == 2);

	assert(findByMaterial(v,m)->quantity == 246);
	destroyMaterial(m);
	destroyRepo(v);
}

void testRemove()
{

	DATE d1;
	d1.day = 12;
	d1.month = 9;
	d1.year = 2019;
	Material* m = createMaterial("cheese1", "doctor_cheese1", 123, d1);

	MaterialRepo* v = createRepo();
	initMaterialRepoForTests(v);
	assert(getLengthRepo(v) == 1);

	assert(addMaterial(v, m) == 1);
	removeM(v, m);
	destroyMaterial(m);
	assert(getLengthRepo(v) == 1);

	Material* m1 = createMaterial("butter", "doctor_butter", 1223, d1);

	removeM(v, m1);
	destroyMaterial(m1);
	destroyRepo(v);

}

void testUpdate()
{
	DATE d1;
	d1.day = 12;
	d1.month = 9;
	d1.year = 2019;
	Material* m = createMaterial("cheese", "doctor_cheese", 123, d1);

	MaterialRepo* v = createRepo();
	
	assert(getLengthRepo(v) == 0);
	assert(addMaterial(v, m));
	Material* m1 = createMaterial("butter", "doctor_butter", 1223, d1);

	assert(updateM(v, m1) == 0);

	assert(updateM(v, m) == 1);
	destroyMaterial(m);
	destroyMaterial(m1);
	
	destroyRepo(v);

}


void testsPlanetRepo()
{
	testAdd();
	testRemove();

}

