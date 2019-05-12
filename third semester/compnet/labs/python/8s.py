from socket import *
import os

s = socket(AF_INET, SOCK_STREAM)
s.bind(('localhost', 1234))
s.listen(5)

while True:
	print('running')
	conn, addr = s.accept()
	if os.fork() == 0:
		alist = [i for i in conn.recv(4).decode().split(' ')]
		blist = [i for i in conn.recv(4).decode().split(' ')]
		clist = [i for i in alist if i not in blist]
		conn.send(' '.join(clist).encode())
		conn.close()
		break
s.close()		
