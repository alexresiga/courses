import os
from socket import *

sock = socket(AF_INET, SOCK_DGRAM)
server_address1 = ('0.0.0.0', 1234)
sock.bind(server_address1)

port = 1234

data, address = sock.recvfrom(1024)

if data:
	port = port + 1
	sent = sock.sendto(str(port).encode(), address)
	print("starting new process on port: {}".format(str(port)))
	s = socket(AF_INET, SOCK_DGRAM)
	s.bind(('0.0.0.0', port))
	data, address2 = s.recvfrom(1024)
	if os.fork():
		while(1):
			data, address1 = s.recvfrom(1024)
			print("[{}]: {}".format("user",data.decode()))
	else:
		while(1):
			b = input()
			s.sendto(b.encode(), address2)
