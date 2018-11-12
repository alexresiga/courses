#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

struct stat st;

int main(int argc, char* argv[])
{
	int p2c[2], c2p[2];
	pipe(p2c);pipe(c2p);
	stat(argv[1], &st);
	size = st.st_size;
	
}
