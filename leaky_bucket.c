#include <stdio.h>

int main() {
	int size, out_rate, n;
	printf("Enter bucket size: ");
	scanf("%d", &size);
	printf("Enter Outgoing rate: ");
	scanf("%d", &out_rate);
	printf("Enter number of packets: ");
	scanf("%d", &n);
	puts("");

	int store = 0;
	while(n > 0) {
		printf("\nEnter incoming packet size: ");
		int incoming;
		scanf("%d", &incoming);
		int rem = size - store;
		if(incoming <= rem) {
			store += incoming;
		}
		else {
			printf("Dropped %d packets\n", incoming - (size - store));
			store = size;
		}
		printf("Bucket size: %d/%d\n", store, size);	
		store -= out_rate;
		printf("After outgoing, bucket size: %d/%d\n", store, size);
		n--;
	}
}
