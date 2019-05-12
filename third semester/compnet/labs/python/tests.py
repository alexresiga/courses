from socket import *
import os

s = socket(AF_INET, SOCK_STREAM)
s.bind(('localhost', 1234))
s.listen(5)

while True:
	print('running..')
	cs, addr = s.accept()
	if os.fork() == 0:
		total = 2
		correct = 0
		question = "in ce an suntem"
		answers = ' '.join(["2017", "2018", "2019"])
		content = question + ';'  + answers
		cs.sendall(content.encode())
		user = cs.recv(1024).decode()
		if user == "2018":
			correct = correct + 1
		question2 = "in ce cladire suntem"
		answers2 = ' '.join(["fsega", "centrala", "avram iancu"])
		content2 = question2 + ';' + answers2
		cs.sendall(content2.encode())
		user2 = cs.recv(1024).decode()
		if user2 == "fsega":
			correct = correct + 1
		stat = "ai raspuns corect la {} din {} intrebari".format(correct, total)
		cs.sendall(stat.encode())
		cs.close()
		break
s.close()
