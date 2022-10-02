#include "p1_cprog02.h"

void p1_cprog02() {
	int a, n, amount;

	printf("제곱할 수:");
	scanf("%d", &a);
	printf("제곱할 횟수:");
	scanf("%d", &n);

	amount = 1;

	for (int i = 0; i < n; ++i) {
		for(int j = 0; j < i; j++) {
			printf("%d*", a);
		}

		amount *= a;
		printf("%d=%d\n", a, amount);
	}

	printf("결과의 합:%d\n", amount);
}

