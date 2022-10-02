#include "p2_cprog01.h"

void p2_cprog01() {
	int input = -1;

	while(input != 0) {
		print_p2_cprog01_prompt();
		scanf("%d", &input);
		switch(input) {
			case 1:
				p1_cprog00();
				break;
			case 2:
				p1_cprog01();
				break;
			case 3:
				p1_cprog02();
				break;
			case 4:
				p1_cprog03();
				break;
			case 5:
				p1_cprog04();
				break;
			case 6:
				p2_cprog02();
				break;
			case 7:
				p2_cprog03();
				break;
			case 0:
				printf("프로그램을 종료합니다.\n");
				break;
			default:
				printf("잘못 입력하셨습니다. 다시 입력해주세요.\n");
				break;
		}
	}
}

void print_p2_cprog01_prompt() {
	printf("1. int값 1개를 입력받고 그 수만큼 HelloWorld!를 출력하는 프로그램\n2. int값 2개를 입력받고 첫 번째 수만큼 띄우고 두 번째 수만큼 Hello!를 출럭하는 프로그램\n3. 제곱하는 수와 제곱할 횟수를 입력받아 연산과정과 결과를 출력하는 프로그램\n4. 0보다 작은 음수가 나올 때 까지 수를 입력받아 연산과정과 결과를 출력하는 프로그램\n5. 구구단 프로그램\n6. 배열을 이용한 성적 처리 프로그램\n7. 동적배열을 이용한 성적 처리 프로그램\n0. 프로그램 종료\n선택 : ");
}
