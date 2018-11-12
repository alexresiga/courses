#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
             
#define max 100
 
int main() {
  int c;
  uint8_t cod, r;
  //int32_t r;
  char buffer[1024];
  struct sockaddr_in server;
  char s[max];
  
  c = socket(PF_INET, SOCK_STREAM, 0);
  if (c < 0) {
    fprintf(stderr, "Eroare la creare socket client.\n");
    return 1;
  }
  
  memset(&server, 0, sizeof(struct sockaddr_in));
  server.sin_family = AF_INET;
  server.sin_port = htons(1234);
  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  
  cod = connect(c, (struct sockaddr *) &server, sizeof(struct sockaddr_in));
  if (cod < 0) {
    fprintf(stderr, "Eroare la conectarea la server.\n");
    return 1;
  }
  
  printf("Dati o fraza pentru trimis la server: ");
  fgets(s, max, stdin);
  
  // !!! important - trimit lungimea sirului + 1 pentru a trimite pe socket si caracterul NULL (0) care marcheaza sfarsitului sirului.
  // paragraful 1 din protocol
  cod = send(c, s, strlen(s) + 1, 0);
  if (cod != strlen(s) + 1) {
    fprintf(stderr, "Eroare la trimiterea datelor la server.\n");
    return 1;
  }
  
  // paragraful 5 din protocol
  cod = recv(c, buffer, sizeof(uint8_t), MSG_WAITALL);
  //r = ntohl(r);
  if (cod != sizeof(int)) {
    fprintf(stderr, "Eroare la primirea datelor de la client.\n");
    //return 1;
  }
  
  printf("Serverul a returnat %s caractere spatiu in sirul trimis.\n", buffer);
  
  close(c);
}
 
