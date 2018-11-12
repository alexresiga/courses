from socket import *
import os

sock = socket(AF_INET, SOCK_DGRAM)
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
			print("starting new process on port: {}".format(str(port)))
			s = socket(AF_INET, SOCK_DGRAM)
			s.bind(('localhost', port))
			string, address1 = s.recvfrom(4096)
			character, address1 = s.recvfrom(4096)
			string, character  = string.decode(), character.decode()
			result = ' '.join([str(i) for i in range(len(string)) if string[i] == character]).encode()
			print(result.decode())
			s.sendto(result, address1)

