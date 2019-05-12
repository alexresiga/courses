from socket import *
import os
from pathlib import Path
s = socket(AF_INET, SOCK_STREAM)
s.bind(('localhost', 1234))
s.listen(5)

while True:
	cs, addr = s.accept()
	print('running..')
	if os.fork() == 0:
		a = cs.recv(1024).decode()
		try:
			res = os.path.getsize(a)
			with open(a) as f: ceva  = f.read()
			new = a+'-copy'
			Path(new).write_text(ceva)
		except(os.error):
			res = -1
		cs.send(str(res).encode())
		cs.send(' '.join(map(str, ceva)).encode())
		cs.close()
		break

s.close()
