#include <stdio.h>

int main() {
  printf("Enter total no. of frames: ");
  int n;
  scanf("%d", &n);
  printf("Enter window size: ");
  int w;
  scanf("%d", &w);

  puts("");
  puts("--- Go back N Simulation ---");

  int base = 0;
  while (base < n) {
    printf("\nSending frames: ");
    for (int i = base; i < base + w && i < n; ++i) {
      printf("%d ", i);
    }
    printf("\nEnter last ACK received (-1 for error): ");
    int ack;
    scanf("%d", &ack);
    if (ack == -1) {
      printf("Error occured! Retransmitting from frame %d\n", base);
    }
    else {
      printf("ACK received for frame %d\n", ack);
      base = ack + 1;
    }
  }
  printf("\nAll frames transmitted successfully\n");
  return 0;
}
