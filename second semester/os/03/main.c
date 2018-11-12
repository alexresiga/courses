#include <stdio.h>
#include <stdlib.h>

int main()
{	
	int* pn;
	int n;
	pn = &n;
	
	scanf("%d", pn);
	int **x = (int**)malloc(n*sizeof(int*));
	
	for (int i = 0; i < *pn; ++i)
	{
		x[i] = (int*)malloc(n*sizeof(int));
		for (int j = 0; j < *pn; ++j)
		{
			scanf("%d", &x[i][j]);
		}
	}
	

	for (int i=0; i < *pn; ++i)
		free(x[i]);
	free(x);	
return 0;
}

