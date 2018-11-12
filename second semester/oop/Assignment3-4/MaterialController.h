#pragma once
#include "MaterialRepo.h"
#include "OperationsStack.h"

typedef struct
{
	MaterialRepo* repo;
	OperationsStack* undoStack;
	OperationsStack* redoStack;
} Controller;

typedef DynamicArray*(*sorting)(DynamicArray*);

/*
	creates a controller based ona repository r
*/
Controller* createController(MaterialRepo* r, OperationsStack* undoS, OperationsStack* redoS);

/*
	destroys the controller and frees the memory
*/
void destroyController(Controller* c);

/*
	controller function for adding a material
	input: c controller and name, supplier, qty, date parameters for creating the to-be-added material
	output: 1 if the adding was successful, 0 otherwise
*/
int addMaterialCtrl(Controller* c, char* name, char* supplier, int qty, DATE date);


/*
	controller function for getting an iterator of the repository
	input: c a controller
*/
MaterialRepo* getRepo(Controller* c);

/*
	controller function for removing a material
	input: c controller and name, supplier, qty, date parameters for creating the to-be-removed material
	output: 1 if the removal was successful, 0 otherwise
*/
int removeMaterial(Controller* c, char* name, char* supplier, DATE date);

/*
	controller function for updating a material
	input: c a controller, m old materail, n new material
	output: 1 if the update was successful, 0 otherwise
	
*/
int updateMaterial(Controller* c, Material* m);

/*
	return repo based on search query and past their expiration date
	input: c a controller , char string searched string 
	output: material repo containing desired items
*/
DynamicArray* getAvailableMaterials(Controller* c, char string[]);

/*
	return a repo of materials which have a given supplier
	input: c a controller and string the given string
	output: matearial repo containing materials from that supplier
*/
DynamicArray* givenSupplier(Controller* c, char string[], int, sorting);

/*
	function that sorts a dynamic array on an ascending criteria
	input: arr a DynamicArray
	output: sorted dynamicArray
*/
DynamicArray* ascendingSort(DynamicArray*);


/*
	function that sorts a dynamic array on an descending criteria
	input: arr a DynamicArray
	output: sorted dynamicArray
*/
DynamicArray* descendingSort(DynamicArray*);

/*
	function that filters elements of a dynamic array that have quantity in a given range
	input: c a controller, int low - lower bound, int high - upper bound
	output: a dynamic array containing only valid materials

*/
DynamicArray* customFilter(Controller*, int, int);

/*
	function that calls the undo on the operation stack
	input:c a controller
	output: 1 if there is any undo to be done, 0 if there are no operations left to be undone
*/
int undo(Controller*);

/*
function that calls the redo on the operation stack
input:c a controller
output: 1 if there is any redo to be done, 0 if there are no operations left to be redone
*/
int redo(Controller*);

DynamicArray* lab4Activity(DynamicArray*, char string[]);

//TESTS
void testsMaterialController();