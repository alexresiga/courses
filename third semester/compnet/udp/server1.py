import socket
import os

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_address = ('localhost', 1234)
sock.bind(server_address)

port = 1234

while True:
	data, address = sock.recvfrom(4096)
	print(data.decode())
	if data:
		port = port + 1
		sent = sock.sendto(str(port).encode(), address)
		if os.fork():
			print('starting new process on port: {}'.format(str(port)))
			s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
			s.bind(('localhost', port))
			alist, address2 = s.recvfrom(4096)
			array = sum([int(i) for i in alist.decode().split(' ')])
			print(array)
			s.sendto(str(array).encode(), address2)
			
