void citeste(int fd, char* buffer, int size)
{
	int n=0;
	while (n<size)
		n+=read(fd, (char*)((size_t)buffer+n),size-n);
}
int fd = open(filename, O_RDONLY);
int size = lseek(fd, 0, SEEK_END);
lseek(fd, 0, SEEK_SET);
