#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct packet {
  int data;
  char ack;
};

int main() {
  int n;
  printf("Enter no. of packets to sent: ");
  scanf("%d", &n);
  struct packet p[n];

  for (int i = 1; i <= n; ++i) {
    printf("\nEnter data for packet[%d]: ", i);
    scanf("%d", &p[i].data);
    p[i].ack = 'y';
  }
  // randomly select a packet to lose
  int r = rand() % n + 1;
  p[r].ack = 'n';
  printf("Packet number %d is not received\n", r);
  printf("\nResending packet %d...", r);
  sleep(2);
  p[r].ack = 'y';
  printf("\nThe received packet is %d\n", p[r].data);
  puts("All packets sent successfully!");
  return 0;
}
