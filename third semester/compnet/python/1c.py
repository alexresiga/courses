import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

s.connect(('localhost', 1234))

n = int(input("n="))

alist= []
for i in range(n):
	alist.append(int(input()))
ceva = ' '.join(map(str, alist))
s.sendall(ceva.encode())

response = s.recv(1024).decode()
print(response)
s.close()
