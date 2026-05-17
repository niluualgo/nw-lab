
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
  char msg[100];
  int fd = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in s = {
      .sin_family = AF_INET,
      .sin_addr.s_addr = inet_addr("127.0.0.1"),
      .sin_port = htons(3004),
  };

  bind(fd, (struct sockaddr*)&s, sizeof(s));
  listen(fd, 20);

  int tmpfd = accept(fd, NULL, NULL);

  while (1) {
    recv(tmpfd, msg, sizeof(msg), 0);
    printf("\nMessage got from client: %s", msg);
    printf("Enter data to send to client: ");

    fgets(msg, 100, stdin);
    if (strncmp(msg, "end", 3) == 0) break;
    send(tmpfd, msg, 100, 0);
  }

  close(tmpfd);
  close(fd);
}
