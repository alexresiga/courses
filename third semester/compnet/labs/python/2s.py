from socket import *
import os

s = socket(AF_INET, SOCK_STREAM)

s.bind(('localhost', 1234))

s.listen(5)

while True:
	print('running..')
	cs, addr = s.accept()
	if os.fork() == 0:
		print("child " + str(os.getpid()))
		a = cs.recv(1024).decode()
		print(a)
		cs.send(str(a.count(' ')).encode())
		cs.close()
		break
s.close()
