#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  int sockfd;
  struct sockaddr_in client;
  memset(&client, 0, sizeof(client));
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    puts("Error in socket creation!");
    exit(1);
  }
  client.sin_family = AF_INET;
  client.sin_addr.s_addr = INADDR_ANY;
  client.sin_port = 3003;

  int k = connect(sockfd, (struct sockaddr*)&client, sizeof(client));
  if (k == -1) {
    puts("Error in connecting to server");
    exit(1);
  }

  while (1) {
    printf("\nEnter data to send to server: ");
    char msg[100];
    fgets(msg, 100, stdin);
    if (strncmp(msg, "end", 3) == 0) break;
    int k = send(sockfd, msg, 100, 0);
    if (k == -1) {
      puts("Error in sending");
      exit(1);
    }
    k = recv(sockfd, msg, 100, 0);
    if (k == -1) {
      puts("Error in receiving");
      exit(1);
    }
    printf("Message got from server: %s\n", msg);
  }
  close(sockfd);
  return 0;
}
