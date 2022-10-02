#include "p1_cprog03.h" 

void p1_cprog03() {
	double amount = 0;
	int num = -1;
	int input = 0;

	while (input >= 0) {
		amount += input;
		++num;

		printf("수 입력:");
		scanf("%d", &input);
	}

	printf("총점 : %d\n", (int)(amount));
	printf("평균 : %d\n", (int)(amount / num));
}
