from socket import *
import os

s = socket(AF_INET, SOCK_STREAM)
s.bind(('localhost', 1234))
s.listen(5)

while True:
	print('running..')
	cs, addr = s.accept()
	if os.fork() == 0:
		a = cs.recv(1024).decode()
		cs.send(''.join(map(str, reversed(a))).encode())
		cs.close()
		break
s.close()
