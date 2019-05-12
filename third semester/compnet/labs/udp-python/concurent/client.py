import socket
import sys

# Create a UDP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

server_address = ('localhost', 5000)
message = "msg"

try:

    # Send data
    print >>sys.stderr, 'sending "%s"' % message
    sent = sock.sendto(message, server_address)
            
    print >>sys.stderr, 'waiting to receive'
    data, server = sock.recvfrom(4096)
    print >>sys.stderr, 'received "%s"' % data

    sock2 = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    server_address2 = ('localhost', int(data))
    
    n1 = raw_input("n1= ")
    n2 = raw_input("n2= ")
    
    sent = sock2.sendto(n1, server_address2)
    sent = sock2.sendto(n2, server_address2)
    
    data, server = sock2.recvfrom(4096)
    
    print (data)
    
finally:
  print >>sys.stderr, 'closing socket'
  sock.close()