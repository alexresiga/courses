import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_address1 = ('localhost', 1234)
message = 'trying to connect'

try:
	sent = sock.sendto(message.encode(), server_address1)
	port, server = sock.recvfrom(4096)
	s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
	server_address = ('localhost', int(port.decode()))
	alist = ' '.join([input() for x in range(5)])
	sent = s.sendto(alist.encode(), server_address)
	data, server = s.recvfrom(4096)
	print(data.decode())

finally:
	sock.close()
