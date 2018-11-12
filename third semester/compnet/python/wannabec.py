from socket import *

s = socket(AF_INET, SOCK_STREAM)

s.connect(('localhost', 1234))

a = input("enter path ")

s.sendall(a.encode())

response = s.recv(1024).decode()
print(response)

res = s.recv(1024).decode()
print(res)
s.close()
