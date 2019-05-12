from socket import *

s = socket(AF_INET, SOCK_STREAM)
s.connect(('localhost', 1234))

a = input("enter string: ")
b = input("enter character: ")

s.sendall(a.encode())
s.sendall(b.encode())

response = s.recv(1024).decode()

print(response)
s.close()
