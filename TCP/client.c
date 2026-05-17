#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
  char msg[100];
  int fd = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in client = {
      .sin_family = AF_INET,
      .sin_port = htons(3004),
  };

  connect(fd, (struct sockaddr*)&client, sizeof(client));

  while (1) {
    printf("\nEnter data to send to server: ");
    fgets(msg, 100, stdin);
    if (strncmp(msg, "end", 3) == 0) break;

    send(fd, msg, 100, 0);
    recv(fd, msg, 100, 0);

    printf("Message got from server: %s\n", msg);
  }
  close(fd);
}
