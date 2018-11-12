//each command has their own command line arguments with escaped semi columns
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char** argv)
{
	int i, k, j, n=0;
	char** a;
	i=1;
	while(i < argc){
		 k = 0;
		while (i+k < argc && strcmp(argv[i+k], ";")){
			k++;
		}
		/*
		replace 
		argv[i+k] = NULL;
		n++;
		if ( fork() == 0){
		execvp(argv[i], argv+i);
		exit(1);
		}
		i+=k+1;
		*/	
		a = (char**)malloc((k+1)*sizeof(char*));
		for (j = 0; j < k; j++) {
			a[j] = argv[i+j];
		}
		a[k] = NULL;n++;
		if (fork() == 0){
			execvp(a[0], a);
			free(a);
			exit(1);
		}
		i += k+1;
		free(a);
	}
	for (i=0;i<n;i++){
		wait(0);	
	}

return 0;	
}

