from socket import *
import os
  
sock = socket(AF_INET, SOCK_DGRAM)
server_address1 = ('localhost', 1234)
msg = 'here to connect'

try:
	sent = sock.sendto(msg.encode(), server_address1)
	port, server = sock.recvfrom(1024)
	s = socket(AF_INET, SOCK_DGRAM)
	server_address = ('localhost', int(port.decode()))
	s.sendto('ce'.encode(), server_address)
	if os.fork():
		while(1):
			a = input()
			sent = s.sendto(a.encode(), server_address)
				
	else:
		while(1):
			data, server = s.recvfrom(1024)
			print("[{}]: {}".format("server", data.decode()))

finally:
        sock.close()
