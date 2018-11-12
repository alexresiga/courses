//if the program runs for more than 10 seconds kill all child processes and exit
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
int n=0;
int* pid;

void stop( int sig)
{
	int i;
	for(i=0;i<n;i++)
{	
	kill(pid[i], SIGKILL);
	wait(0);
}
free(pid);
exit(1);
}

int main(int argc, char** argv)
{
	int i, k, j;
	pid  = (int*)malloc(argc*sizeof(int));
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
		a[k] = NULL;pid[n++]=fork();
		if (pid[n-1] == 0){
			execvp(a[0], a);
			free(a);
			exit(1);
		}
		i += k+1;
		free(a);
	}
	signal(SIGALRM, stop);
	alarm(10);
	for (i=0;i<n;i++){
		wait(0);	
	}
free(pid);
return 0;	
}
