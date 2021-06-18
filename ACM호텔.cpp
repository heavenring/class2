#include<stdio.h>

void find(int count, int room, int layer, int customer) {
	int r, l;
	for (r = 1; r <= room; r++)
		for (l = 1; l <= layer; l++) {
			count += 1;
			if (customer == count) {
				printf("%d\n", l * 100 + r);
				break;
			}
		}
}

int main() {

	int hotel[100][100];
	int t, layer, room, customer;

	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d %d %d", &layer, &room, &customer);
		find(0, room, layer, customer);
	}
}