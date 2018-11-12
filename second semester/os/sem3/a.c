//implement a C program that takes as command line args commands and executes them concurrently.
// int main( int argc, char** argv) argc= 5 and argv = {"./myprog", "ls", "pwd", "who", "date", NULL}
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char** argv)
{
	int i;
	for (i=1; i<argc;i++)
	{
		if (fork() == 0)
		{	
			execlp(argv[i],argv[i], NULL);
			exit(1);
		}
	} 
	for (i=1;i<argc;i++)
		wait(0);

return 0;	
}
