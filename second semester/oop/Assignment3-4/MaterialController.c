#define _CRT_SECURE_NO_WARNINGS
#include "MaterialController.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>


DATE CURRENT_DATE;

Controller* createController(MaterialRepo* r, OperationsStack* undoS, OperationsStack* redoS)
{
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	CURRENT_DATE.day = timeinfo->tm_mday;
	CURRENT_DATE.month = timeinfo->tm_mon+1;
	CURRENT_DATE.year = timeinfo->tm_year+1900;

	Controller* c = (Controller*)malloc(sizeof(Controller));
	c->repo = r;
	c->undoStack = undoS;
	c->redoStack = redoS;
	return c;
}

void destroyController(Controller* c)
{
	destroyRepo(c->repo);

	destroyStack(c->undoStack);

	destroyStack(c->redoStack);

	free(c);
}

int addMaterialCtrl(Controller* c, char* name, char* supplier, int qty, DATE date)
{
	Material* m = createMaterial(name, supplier, qty, date);

	int res = addMaterial(c->repo, m);

	if (res == 1)
	{
		Operation* o = createOperation(m, "add");
		push(c->undoStack, o);
		destroyOperation(o);
		emptyStack(c->redoStack);
	}

	destroyMaterial(m);

	return res;
}

MaterialRepo* getRepo(Controller* c)
{
	return c->repo;
}

int undo(Controller* c)
{
	if (isEmpty(c->undoStack))
		return 0;

	Operation* operation = pop(c->undoStack);

	if (!strcmp(getOperationType(operation), "add"))
	{
		Material* m = getMaterialStack(operation);

		//redo
		Operation* o = createOperation(m, "add");
		push(c->redoStack, o);
		destroyOperation(o);
		//end of redo

		removeM(c->repo, m);
		destroyOperation(operation);

		

	}
	else if (!strcmp(getOperationType(operation), "remove"))
	{
		Material* m = getMaterialStack(operation);

		//redo
		Operation* o = createOperation(m, "remove");
		push(c->redoStack, o);
		destroyOperation(o);
		//end of redo

		addMaterial(c->repo, m);
		destroyOperation(operation);
	}
	else if (!strcmp(getOperationType(operation), "update"))
	{
		Material* m = getMaterialStack(operation);
		updateM(c->repo, m);
		//destroyOperation(operation);
	}
	 
	return 1;
}

int redo(Controller* c)
{
	if (isEmpty(c->redoStack))
		return 0;

	Operation* operation = pop(c->redoStack);

	if (!strcmp(getOperationType(operation), "add"))
	{
		Material* m = getMaterialStack(operation);
		addMaterial(c->repo, m);
		destroyOperation(operation);
	}
	else if (!strcmp(getOperationType(operation), "remove"))
	{
		Material* m = getMaterialStack(operation);
		removeM(c->repo, m);
		destroyOperation(operation);
	}
	else if (!strcmp(getOperationType(operation), "update"))
	{
		Material* m = getMaterialStack(operation);
		updateM(c->repo, m);

	}
	return 1;
}


int removeMaterial(Controller* c, char* name, char* supplier, DATE date)
{
	Material* m = createMaterial(name, supplier, 0, date);
	int startLength = getLengthRepo(c->repo);
	removeM(c->repo, m);

	if (getLengthRepo(c->repo) == startLength)
		return 0;
	else {
		Operation* o = createOperation(m, "remove");
		push(c->undoStack, o);
		destroyOperation(o);
		emptyStack(c->redoStack);
	}
	destroyMaterial(m);
	return 1;
}

int updateMaterial(Controller* c, Material* m)
{
	Material* old = copyMaterial(findByMaterial(c->repo, m));
	int res = updateM(c->repo, m);
	if (res == 1)
	{ 
		Operation* op = createOperation(m, "update");
		push(c->redoStack, op);
		destroyOperation(op);

		Operation* o = createOperation(old, "update");
		push(c->undoStack, o);
		destroyOperation(o);
	}
	return res;
}



DynamicArray* getAvailableMaterials(Controller* c, char string[])
{
	DynamicArray* res = createDynamicArray(10, destroyMaterial);

	if (!strcmp(string, ""))
		for (int i = 0; i < getLengthRepo(c->repo); ++i)
		{
			Material* m = getMaterial(c->repo, i);
			if (compareTime(getExprDate(m), CURRENT_DATE) == -1)
				add(res, m);
		}
	else {
		for (int i = 0; i < getLengthRepo(c->repo); ++i)
		{
			Material* m = getMaterial(res, i);
			if (strstr(getName(m), string) != NULL || strstr(getSupplier(m), string) != NULL)
				if (compareTime(getExprDate(m), CURRENT_DATE) == -1)
					add(res, m);
		}
	}
	return res;
	
}

DynamicArray* customFilter(Controller* c, int low, int high)
{
	DynamicArray* res = createDynamicArray(10, destroyMaterial);
	for (int i = 0; i < getLengthRepo(c->repo); ++i)
	{
		Material* m = getMaterial(c->repo, i);
		if (low <= getQty(m) && getQty(m) <= high) 
			add(res, m);
	}

	return res;
}

DynamicArray* ascendingSort(DynamicArray* res)
{
	Material* aux = createMaterial("", "", 0, (DATE) { 1, 1, 1900 });
	for (int i = 0; i < getLength(res) - 1; ++i)
	{
		for (int j = i + 1; j < getLength(res); ++j)
		{
			if (getQty(res->elems[i]) - getQty(res->elems[j]) > 0)
			{
				aux = res->elems[i];
				res->elems[i] = res->elems[j];
				res->elems[j] = aux;
			}

		}

	}
	return res;
}

DynamicArray* descendingSort(DynamicArray* res)
{
	Material* aux = createMaterial("", "", 0, (DATE) { 1, 1, 1900 });
	for (int i = 0; i < getLength(res) - 1; ++i)
	{
		for (int j = i + 1; j < getLength(res); ++j)
		{
			if (getQty(res->elems[i]) - getQty(res->elems[j]) < 0)
			{
				aux = res->elems[i];
				res->elems[i] = res->elems[j];
				res->elems[j] = aux;
			}

		}

	}
	return res;
}

DynamicArray* givenSupplier(Controller* c, char string[], int qty, sorting chosenSort)
{
	DynamicArray* res = createDynamicArray(10, destroyMaterial);
	
	for (int i = 0; i < getLengthRepo(c->repo); ++i)
	{	
		Material* m = getMaterial(c->repo, i);

		if (!strcmp(getSupplier(m), string) && getQty(m) < qty)
			add(res, m);
	}
	chosenSort(res);
}

DynamicArray* lab4Activity(Controller* c, char string[])
{
	DynamicArray* res = createDynamicArray(10, destroyMaterial);

	for (int i = 0; i < getLengthRepo(c->repo); ++i)
	{
		Material* m = getMaterial(c->repo, i);
		if (!strcmp(getSupplier(m), string))
			add(res, m);
	}
	
	Material* aux = createMaterial("", "", 0, (DATE) { 1, 1, 1900 });
	for (int i = 0; i < getLength(res) - 1; ++i)
	{
		for (int j = i + 1; j < getLength(res); ++j)
		{
			if (getExprDate(res->elems[i]).month - getExprDate(res->elems[j]).month > 0)
			{
				aux = res->elems[i];
				res->elems[i] = res->elems[j];
				res->elems[j] = aux;
			}

		}

	}
	return res;
}

//TESTS

void initControllerForTests(Controller* c)
{
	DATE d1;
	d1.day = 12;
	d1.month = 9;
	d1.year = 2019;

	addMaterialCtrl(c, "milk", "smoeby", 123, d1);
}

void testAddMaterial()
{	
	MaterialRepo* r = createRepo();
	OperationsStack* undoS = createStack();
	OperationsStack* redoS = createStack();
	Controller* c = createController(r, undoS, redoS);

	initControllerForTests(c);
	DATE d1;
	d1.day = 12;
	d1.month = 9;
	d1.year = 2019;
	assert(addMaterialCtrl(c, "milk", "smoeby", 123, d1) == 1);

	destroyController(c);
}

void testsMaterialController()
{
	testAddMaterial();
}