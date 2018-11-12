from socket import *

sock = socket(AF_INET, SOCK_DGRAM)
server_address1 = ('localhost', 1234)
msg = 'here to connect'

try:
	sent = sock.sendto(msg.encode(), server_address1)
	port, server = sock.recvfrom(4096)
	s = socket(AF_INET, SOCK_DGRAM)
	server_address = ('localhost', int(port.decode()))
	a = input("enter string: ")
	b= input("enter character: ")
	sent = s.sendto(a.encode(), server_address)
	sent = s.sendto(b.encode(), server_address)
		
	data, server = s.recvfrom(1024)
	print(data.decode())

finally:
	sock.close()
