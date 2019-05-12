import time
import os
import socket

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind(('localhost', 1234))
s.listen(5)

while True:
	print('Running')
	cs, address = s.accept()
	if os.fork() == 0:
		a = cs.recv(1024).decode()
		print('received a')
		n = int(a)
		alist = [d for d in range(1, n//2+1) if n%d == 0] 		
		print(alist)
		res = ' '.join(map(str, alist))
		
		cs.send(res.encode())
		cs.close()
		break

