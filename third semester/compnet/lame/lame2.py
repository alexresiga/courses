import socket
from struct import *
from random import *

n = int(input("Give the number of elements: "))
arr = []
for i in range(n):
    arr.append(randint(1, 100))
print(arr)
c = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
c.connect(('172.30.117.236', 4444))
r = pack('>i ', len(arr))
c.send(r)
for i in range(len(arr)):
    r = pack('>i', arr[i])
    c.send(r)
#chunk = 0
chunk = c.recv(4)
chunk = unpack('<i', chunk)
n = chunk[0]
for i in range(n):
    chunk = c.recv(4)
    chunk = unpack('<i', chunk)
    print(chunk[0])
    #arr[i] = chunk[0]
c.close()
