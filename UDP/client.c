#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  int sockfd;
  struct sockaddr_in server, client;
  socklen_t addr_len;
  char msg[100];

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    printf("Socket creation failed!\n");
    exit(1);
  }

  server.sin_family = AF_INET;
  server.sin_port = htons(3002);
  server.sin_addr.s_addr = inet_addr("127.0.0.1");

  addr_len = sizeof(server);

  // send msg to server
  strcpy(msg, "Hello from client");
  sendto(sockfd, msg, strlen(msg), 0, (struct sockaddr*)&server, addr_len);

  // recv response from server
  recvfrom(sockfd, msg, sizeof(msg), 0, (struct sockaddr*)&server, &addr_len);
  printf("Server: %s\n", msg);

  close(sockfd);
  return 0;
}
