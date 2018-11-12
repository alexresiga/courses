#include "Repository.h"
#include "Domain.h"
#include <stdlib.h>
int createVector(VectorArray **materialList)
{
	*materialList = (VectorArray*)malloc(sizeof(VectorArray));
	if (*materialList == NULL)
		return -1;
	(**materialList).array = (Material*)malloc(10*sizeof(Material));
	if ((**materialList).array == NULL)
		return -1;

	return 0;
}

int destroyVector(VectorArray **materialList)
{
	free((**materialList).array);
	free(*materialList);

	return 0;
}

