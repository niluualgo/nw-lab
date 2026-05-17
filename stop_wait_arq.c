#include <stdio.h>

int main() {
  int n;
  printf("Enter total no. of frames: ");
  scanf("%d", &n);

  printf("\n--- STOP AND WAIT ARQ ---\n");
  int i = 0, seq = 0;
  while(i < n) {
    printf("\nSending frame %d with seq number %d\n", i+1, seq);
    printf("Enter ACK received (0/1/-1): ");
    int ack;
    scanf("%d", &ack);
    if(ack == seq) {
      printf("Frame %d transmitted successfully!\n", i+1);
      seq = 1 - seq; // toggle seq number
      i++;
    }
    else {
      printf("ACK error!. Retransmitting frame %d...\n", i+1);
    }
  }
  printf("\nAll frames transmitted successfully!\n");
}
