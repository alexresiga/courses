from socket import *

with socket(AF_INET, SOCK_STREAM) as s:
	s.connect(('localhost', 1234))
	for i in range(2):
		question, answers = [i for i in s.recv(1024).decode().split(';')]
		print(question)
		print(answers)
		ans = input()
		s.sendall(ans.encode())
	stats = s.recv(1024).decode()
	print(stats)
	s.close()
