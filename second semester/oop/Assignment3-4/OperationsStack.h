#pragma once
#include "DynamicArray.h"
#include <string.h>

typedef struct
{
	Material* material;
	char* operationType;
} Operation;


typedef struct
{
	Operation* operations[100];
	int length;
} OperationsStack;


/*
	creates operation
	input: m a material and a char operation type for redo/undo
	ouput: created operation
*/
Operation* createOperation(Material* m, char* operationType);

/*
destroys operation
input: operation
*/
void destroyOperation(Operation* o);

/*
copies operation
input: o operation
ouput: copied operation
*/
Operation* copyOperation(Operation* o);

/*
gets operation type
input: o operation
ouput: char operation type
*/
char* getOperationType(Operation* o);

/*
gets operation material
input: o operation
ouput: operation material
*/
Material* getMaterialStack(Operation* o);

/*
creates operation stack
ouput: operation stack
*/
OperationsStack* createStack();

/*
destroys operation stack
input: s operation stack
*/
void destroyStack(OperationsStack* s);

/*
push operation on operation stack
input: o operation, s operation stack
*/
void push(OperationsStack* s, Operation* o);

/*
gets operation from operation stack
input: s operation stack
ouput: operation popped
*/
Operation* pop(OperationsStack* s);

/*
checks if operation stack is empty
input: s operation stack
ouput: 1 if empty, 0 otherwise
*/
int isEmpty(OperationsStack* s);

/*
checks if operation stack is full
input: s operation stack
ouput: 1 if full, 0 otherwise
*/
int isFull(OperationsStack* s);

/*
empties operation stack
input: s operation stack
*/
void emptyStack(OperationsStack*);

void testsStack();