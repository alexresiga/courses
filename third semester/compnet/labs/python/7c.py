from socket import *

s = socket(AF_INET, SOCK_STREAM)
s.connect(('localhost', 1234))

a = input("enter string ")
i = input("index: ")
l = input("length: ")
params = ' '.join([i,l])
s.sendall(a.encode())
s.sendall(params.encode())

response = s.recv(1024).decode()
print(response)

s.close()

