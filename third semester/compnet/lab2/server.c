#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>

int main() {

	int s;
	struct sockaddr_in server, client;
	int c, l;

	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s < 0) {
		printf("eroare la conectare server\n");
		return 1;
	}
	
	memset(&server, 0, sizeof(server));
	server.sin_port = htons(1234);
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;

	if (bind(s, (struct sockaddr*) &server, sizeof(server)) < 0) {
		printf("eroare la bind");
		return 1;
	}
	
	listen(s, 5);
	l = sizeof(client);
	while(1) {
		uint8_t msg;
		c = accept(s, (struct sockaddr*) &client, &l);
		printf("s a conectat un client\n");
		recv(c, msg, sizeof(msg), MSG_WAITALL);
		
		send(c, msg, sizeof(msg), 0);
		close(c);
	}
}
