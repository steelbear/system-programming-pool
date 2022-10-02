#include "p1_cprog01.h"

void p1_cprog01() {
	int num_blank;
	int num_hello;

	printf("입력:");
	scanf("%d %d", &num_blank, &num_hello);

	for(int i = 0; i < num_blank; i++) {
		printf("\n");
	}

	for(int i = 0; i < num_hello; i++) {
		printf("Hello World!\n");
	}
}
