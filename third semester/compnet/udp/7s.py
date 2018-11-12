import os
from socket import *

sock = socket(AF_INET, SOCK_DGRAM)
server_address1 = ('0.0.0.0', 1234)
sock.bind(server_address1)

port = 1234

while True:
	data, address = sock.recvfrom(1024)
	print(data.decode())
	if data:
		port = port +1
		sent = sock.sendto(str(port).encode(), address)
		if os.fork():
			print("starting new process on port: {}".format(str(port)))
			s = socket(AF_INET, SOCK_DGRAM)
			s.bind(('0.0.0.0', port))
			string, address1 = s.recvfrom(1024)
			i = int(s.recvfrom(1024)[0].decode())
			l = int(s.recvfrom(1024)[0].decode())
			string  = string.decode()
			result = string[i:i+l]
			sent = s.sendto(result.encode(), address1)

