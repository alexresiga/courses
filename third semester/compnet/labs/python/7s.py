from socket import *
import os

s = socket(AF_INET, SOCK_STREAM)
s.bind(('localhost', 1234))
s.listen(5)

while True:
	print('running')
	conn, addr = s.accept()
	if os.fork() == 0:
		a = conn.recv(1024).decode()
		i, l = [int(i) for i in conn.recv(1024).decode().split(' ')]
		print(l)
		conn.send(''.join(map(str, a[i:i+l])).encode())
		conn.close()
		break
s.close()
