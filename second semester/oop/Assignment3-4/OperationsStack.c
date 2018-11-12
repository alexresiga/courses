#define _CRT_SECURE_NO_WARNINGS
#include "OperationsStack.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

Operation* createOperation(Material* m, char* operationType)
{
	Operation* o = (Operation*)malloc(sizeof(Operation));
	o->material = copyMaterial(m);

	if (operationType != NULL)
	{
		o->operationType = (char*)malloc(sizeof(char) * (strlen(operationType) + 1));
		strcpy(o->operationType, operationType);
	}
	else
		o->operationType = NULL;

	return o;
}


void destroyOperation(Operation* o)
{
	if (o == NULL)
		return;

	// first destroy the material
	destroyMaterial(o->material);
	// then the operationType
	free(o->operationType);
	// then free the operation
	free(o);
}



Operation* copyOperation(Operation * o)
{
	if (o == NULL)
		return NULL;

	Operation* newOp = createOperation(o->material, o->operationType);
	return newOp;
}



char* getOperationType(Operation* o)
{
	return o->operationType;
}

Material* getMaterialStack(Operation* o)
{
	return o->material;
}


// ---------------------------------------------------------------

OperationsStack* createStack()
{
	OperationsStack* s = (OperationsStack*)malloc(sizeof(OperationsStack));
	s->length = 0;

	return s;
}

void emptyStack(OperationsStack* s)
{
	s->length = 0;
}

void destroyStack(OperationsStack* s)
{
	if (s == NULL)
		return;

	// first deallocate memory of operations (this is allocated when a new operation is pushed onto the stack)
	for (int i = 0; i < s->length; i++)
		destroyOperation(s->operations[i]);

	// then free the stack
	free(s);
}



void push(OperationsStack* s, Operation* o)
{
	if (isFull(s))
		return;

	s->operations[s->length++] = copyOperation(o);	// copies of operations are added, such that the stask manages its own operations
}

Operation* pop(OperationsStack* s)
{
	if (isEmpty(s))
		return NULL;
	s->length--;
	return s->operations[s->length];
}

int isEmpty(OperationsStack* s)
{
	return (s->length == 0);
}

int isFull(OperationsStack* s)
{
	return s->length == 100;
}


// Tests
void testsStack()
{
	OperationsStack* s = createStack();

	Material* m1 = createMaterial("lapte", "zuzu", 138, (DATE) {1,1,1900});
	Material* m2 = createMaterial("ipsum", "lorem", 43,(DATE) { 2, 3, 2019 });
	Operation* o1 = createOperation(m1, "add");
	Operation* o2 = createOperation(m2, "add");
	Operation* o3 = createOperation(m1, "remove");

	// the planets may be destroyed, as the operations contain copies of these planets
	destroyMaterial(m1);
	destroyMaterial(m2);

	push(s, o1);
	push(s, o2);
	push(s, o3);

	// the operations may be destroyed, as the stack contains copies of these operations
	destroyOperation(o1);
	destroyOperation(o2);
	destroyOperation(o3);

	assert(isFull(s) == 0);
	assert(isEmpty(s) == 0);
	Operation* o = pop(s);
	assert(strcmp(o->operationType, "remove") == 0);
	// after each pop, the operations must be destroyed
	destroyOperation(o);

	o = pop(s);
	assert(strcmp(o->operationType, "add") == 0);
	destroyOperation(o);

	o = pop(s);
	assert(strcmp(o->operationType, "add") == 0);
	destroyOperation(o);

	assert(isEmpty(s) == 1);

	// destroy the stack
	destroyStack(s);
}