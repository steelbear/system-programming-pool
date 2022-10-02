#include <stdio.h>
#include "cprog04.h"

void printMenu() {
	printf("1. 기본 구구단\n2. 1단부터 n단까지\n3. n단부터 m단까지\n4. n단부터 m단까지 a와 b사이의 곱\n5. 구구단 합까지 출력\n0. 종료\n입력: ");
}

int main() {
	int n, m, a, b, sum;
	int select = -1;

	while(select != 0) {
		printMenu();
		scanf("%d", &select);

		switch(select) {
			case 1:
				sample99v0();
				break;
			case 2:
				printf("n 입력: ");
				scanf("%d", &n);
				sample99v1(n);
				break;
			case 3:
				printf("n m 입력: ");
				scanf("%d %d", &n, &m);
				sample99v2(n, m);
				break;
			case 4:
				printf("n m a b 입력: ");
				scanf("%d %d %d %d", &n, &m, &a, &b);
				sample99v3(n, m, a, b);
				break;
			case 5:
				printf("n m a b 입력: ");
		 	        scanf("%d %d %d %d", &n, &m, &a, &b);
				sum = sample99v4(n, m, a, b);
				printf("합계는 %d입니다.\n", sum);
				break;
			case 0:
				printf("프로그램을 종료합니다.\n");
				break;
			default:
				printf("입력값이 유효하지 않습니다.\n");
				break;
		}
	}

	return 0;
}
