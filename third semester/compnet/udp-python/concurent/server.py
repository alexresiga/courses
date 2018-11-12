import socket
import sys
import os

# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Bind the socket to the port
server_address = ('0.0.0.0', 5000)
print >>sys.stderr, 'starting up on %s port %s' % server_address
sock.bind(server_address)

port = 5000

while True:
  print >>sys.stderr, '\nwaiting to receive message'
  data, address = sock.recvfrom(4096)
            
  print >>sys.stderr, 'received %s bytes from %s' % (len(data), address)
  print >>sys.stderr, data
  if data:
    port = port + 1
    
    sent = sock.sendto(str(port), address)
    
    print >>sys.stderr, 'sent %s bytes back to %s' % (sent, address)
    
    if(os.fork()):
      print("Starting new process on port:")
      print(port)

      sock2 = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
      sock2.bind(('0.0.0.0',port))
      
      n1, address2 = sock2.recvfrom(4096)
      print >>sys.stderr, 'received %s bytes from %s' % (len(n1), address2)
      
      print(n1)

      n2, address2 = sock2.recvfrom(4096)
      print >>sys.stderr, 'received %s bytes from %s' % (len(n2), address2)
      
      print(n2)
      sock2.sendto(str(int(n1) + int(n2)),address2)
      