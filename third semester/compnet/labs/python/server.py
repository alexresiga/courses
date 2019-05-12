import time
import socket
import os
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('localhost', 12345))
s.listen(5)

while True:
	print('Running')
	cs, address = s.accept()
	if os.fork() == 0:
		a = cs.recv(1024)
		print('Received first')
		b = cs.recv(1024)
		print('Received second')
		res = ''.join(map(chr, sorted(a+b)))
		cs.send(res.encode())
		cs.close()
		break
