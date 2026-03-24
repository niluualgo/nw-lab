#include <stdio.h>

int main() {
  printf("Enter number of routers: ");
  int n;
  scanf("%d", &n);

  printf("Enter cost matrix (999 for no-direct link): \n");
  int cost[n][n];
  int dist[n][n];
  int next[n][n];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &cost[i][j]);
      dist[i][j] = cost[i][j];
      next[i][j] = j;
    }
  }

  // Bellman-Ford algorithm
  int updated;
  do {
    updated = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
          if (dist[i][k] + dist[k][j] < dist[i][j]) {
            dist[i][j] = dist[i][k] + dist[k][j];
            next[i][j] = k;
            updated = 1;
          }
        }
      }
    }
  } while (updated);

  for (int i = 0; i < n; ++i) {
    printf("Routing table for router %d: \n", i);
    printf("Destination\tNext Hop\tDistance\n");
    for (int j = 0; j < n; ++j) {
      printf("%d\t\t%d\t\t%d\n", j, next[i][j], dist[i][j]);
    }
    puts("");
  }
}
