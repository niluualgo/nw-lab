#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  int sockfd;
  struct sockaddr_in server_addr, client_addr;
  socklen_t addr_len;
  char msg[100];

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    printf("Socket creation failed!\n");
    exit(1);
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(8080);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
    printf("Bind failed!\n");
    exit(1);
  }

  printf("Server waiting for client...\n");
  addr_len = sizeof(client_addr);

  recvfrom(sockfd, msg, sizeof(msg), 0, (struct sockaddr*)&client_addr,
           &addr_len);
  printf("Client: %s\n", msg);

  strcpy(msg, "Response from UDP server");
  sendto(sockfd, msg, strlen(msg), 0, (struct sockaddr*)&client_addr, addr_len);

  close(sockfd);
  return 0;
}
