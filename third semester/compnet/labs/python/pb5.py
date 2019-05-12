import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('localhost', 1234))

a = input("enter integer: ")
s.sendall(a.encode("utf8"))

response = s.recv(1024).decode("utf8")

print(response)
s.close()
