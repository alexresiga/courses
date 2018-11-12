import socket
import os

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

s.bind(('localhost', 1234))

s.listen(5)

while True:
	print('running')
	cs, addr = s.accept()
	if os.fork() == 0:
		alist = [int(i) for i in cs.recv(1024).decode().split(' ')]
		cs.send(str(sum(alist)).encode())
		cs.close()
		break
		
