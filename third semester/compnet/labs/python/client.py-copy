import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(("127.0.0.1", 12345))
a = input("a: ")
s.sendall(a.encode())
b = input("b: ")
s.sendall(b.encode())
#s.send(b'ceva')
#print('Sent first')
#s.send(b'abcd')
#print('Sent second')
response = s.recv(1024).decode()

print(response)
s.close()
