from socket import *

s = socket(AF_INET, SOCK_STREAM)
s.connect(('localhost', 1234))

a = ''.join(sorted(input('first string: ')))
b = ''.join(sorted(input('second string: ')))
s.sendall(a.encode())
s.sendall(b.encode())

response = s.recv(1024).decode()
print(response)
s.close()



