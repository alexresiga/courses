#pragma once
#include "Material.h"
#include "DynamicArray.h"

typedef struct
{
	DynamicArray* materials;
} MaterialRepo;

MaterialRepo* createRepo();

void destroyRepo(MaterialRepo* v);

/*
	Adds a material to the material repo
	input: v pointer to MaterialRepo
		   m a material
	output: 1 if the material was added successfully, 0 otherwise
*/
int addMaterial(MaterialRepo* v, Material* m);


/*
	Finds if a material already exists in repo
	input: v pointer to MaterailRepo, m a material
	output: the index in the material list if the material exists, -1 otherwise
*/
int find(MaterialRepo* v, Material* m);

/*
	Return pointer to material on specific index
	input: v repository, int index of desired material
	output: existing material from that index, empty material otherwise
*/
Material* getMaterial(MaterialRepo* v, int index);


/*
	Return length of material repo
	input: v a material repo
	output: int length of repository
*/
int getLengthRepo(MaterialRepo* v);

/*
	Remove an existing material from the repo
	input: v a material repo and m a material
*/
void removeM(MaterialRepo* v, Material* m);

/*
	Update an existing material
	input: b a material repo, m old materail, n new material
	output: 1 if the update was successful, 0 otherwise
*/
int updateM(MaterialRepo* b, Material* m);

/*
	overloading comparison for two dates
	input: a,b two DATE structs
	output: 0 if they are the same, -1 if a < b, 1 if a > b
*/
int compareTime(DATE a, DATE b);

/*
	finds if a material is in the repo
	input: a repo and a material
	output: the material identified in the repo or NULL if it doesn't exist
*/
Material* findByMaterial(MaterialRepo*, Material*);

void testsPlanetRepo();