from socket import *

s = socket(AF_INET, SOCK_STREAM)
s.connect(('localhost', 1234))

alist = ' '.join([input() for i in range(5)])
print("second")
blist = ' '.join([input() for i in range(5)])

s.send(alist.encode())
s.send(blist.encode())

response = s.recv(1024).decode()
print(response)
s.close()
