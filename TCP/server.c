#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  int sockfd, tmpsfd;
  struct sockaddr_in server, client;
  memset(&server, 0, sizeof(server));
  memset(&client, 0, sizeof(client));
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    printf("Error in socket creation!\n");
    exit(1);
  }
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  server.sin_port = 3002;
  int k = bind(sockfd, (struct sockaddr*)&server, sizeof(server));
  if (k == -1) {
    printf("Error in binding\n");
    exit(1);
  }
  k = listen(sockfd, 20);
  if (k == -1) {
    printf("Error in listening");
    exit(1);
  }
  socklen_t len = sizeof(client);
  tmpsfd = accept(sockfd, (struct sockaddr*)&client, &len);
  if (tmpsfd == -1) {
    printf("Error in temporary socket creation\n");
    exit(1);
  }
  while (1) {
    char msg[100];
    int k = recv(tmpsfd, msg, 100, 0);
    if (k == -1) {
      printf("Error in receiving\n");
      exit(1);
    }
    printf("Message got from client: %s\n", msg);
    printf("Enter data to send to client: ");
    fgets(msg, 100, stdin);
    if (strncmp(msg, "end", 3) == 0) {
      break;
    }
    k = send(tmpsfd, msg, 100, 0);
    if (k == -1) {
      puts("Error in sending");
      exit(1);
    }
  }
  close(tmpsfd);
  return 0;
}
