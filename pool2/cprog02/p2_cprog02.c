#include "p2_cprog02.h"

void p2_cprog02() {
	int input = -1;

	int korean[10];
	int english[10];
	int math[10];

	korean[0] = -1;
	english[0] = -1;
	math[0] = -1;

	while(input != 0) {
		print_p2_cprog02_prompt();
		scanf("%d", &input);

		switch(input) {
			case 1:
				input_arr(korean, 10);
				break;
			case 2:
				input_arr(english, 10);
				break;
			case 3:
				input_arr(math, 10);
				break;
			case 4:
				average_score(korean, english, math, 10);
				break;
			case 5:
				maximum_score(korean, english, math, 10);
				break;
			case 6:
				minimum_score(korean, english, math, 10);
				break;
			case 7:
				argmax_score(korean, english, math, 10);
				break;
			case 8:
				sort_score_len10(korean, english, math);
				break;
			case 0:
				printf("학생 성적 프로그램을 종료합니다.\n");
				break;
			default:
				printf("잘못 입력하셨습니다 다시 입력해주세요.\n");
				break;
		}
	}
}

void average_score(int* korean, int* english, int* math, int length) {
	if (korean[0] == -1 || english[0] == -1 || math[0] == -1) {
		printf("모든 과목의 성적을 입력하세요.\n");
		return;
	}

	int avg_korean = average_arr(korean, length);
	int avg_english = average_arr(english, length);
	int avg_math = average_arr(math, length);
	printf("국어 %d점 영어 %d점 수학 %d점\n", avg_korean, avg_english, avg_math);
}

void maximum_score(int* korean, int* english, int* math, int length) {
	if (korean[0] == -1 || english[0] == -1 || math[0] == -1) {
		printf("모든 과목의 성적을 입력하세요.\n");
		return;
	}

	int max_korean = maximum_arr(korean, length);
	int max_english = maximum_arr(english, length);
	int max_math = maximum_arr(math, length);
	printf("국어 %d점 영어 %d점 수학 %d점\n", max_korean, max_english, max_math);
}

void minimum_score(int* korean, int* english, int* math, int length) {
	if (korean[0] == -1 || english[0] == -1 || math[0] == -1) {
		printf("모든 과목의 성적을 입력하세요.\n");
		return;
	}

	int min_korean = minimum_arr(korean, length);
	int min_english = minimum_arr(english, length);
	int min_math = minimum_arr(math, length);
	printf("국어 %d점 영어 %d점 수학 %d점\n", min_korean, min_english, min_math);
}

void argmax_score(int* korean, int* english, int* math, int length) {
	if (korean[0] == -1 || english[0] == -1 || math[0] == -1) {
		printf("모든 과목의 성적을 입력하세요.\n");
		return;
	}

	int argmax_korean = argmax_arr(korean, length);
	int argmax_english = argmax_arr(english, length);
	int argmax_math = argmax_arr(math, length);
	printf("국어 %d번 영어 %d번 수학 %d번\n", argmax_korean, argmax_english, argmax_math);
}

void sort_score_len10(int* korean, int* english, int* math) {
	if (korean[0] == -1 || english[0] == -1 || math[0] == -1) {
		printf("모든 과목의 성적을 입력하세요.\n");
		return;
	}

	int sorted_korean[10];
	int sorted_english[10];
	int sorted_math[10];

	copy_arr(korean, sorted_korean, 10);
	copy_arr(english, sorted_english, 10);
	copy_arr(math, sorted_math, 10);

	sort_arr(sorted_korean, 10);
	sort_arr(sorted_english, 10);
	sort_arr(sorted_math, 10);
	
	print_score_arr(sorted_korean, sorted_english, sorted_math, 10);
}

void print_p2_cprog02_prompt() {
	printf(" 1. 국어성적 입력\n 2. 영어성적 입력\n 3. 수학성정 입력\n 4. 각 과목의 평균\n 5. 각 과목의 최고점\n 6. 각 과목의 최저점\n 7. 각 과목의 최고점수 학생번호\n 8. 각 과목의 점수 오름차순\n 0. 종료\n입력 : ");
}

void input_arr(int* arr, int length) {
	int input;
	for(int i = 0; i < length; i++) {
		int input = -1;
		while(input < 0 || input > 100) {
			printf("%d번째 학생: ", i);
			scanf("%d", &input);
			if(input >= 0 && input <= 100) {
				arr[i] = input;
			} else {
				printf("0 ~ 100의 정수를 입력하세요\n");
			}
		}
	}
}

void print_arr(int* arr, int length) {
	for(int i = 0; i < length; i++) {
		printf("%d번 학생 : %d점\n", i, arr[i]);
	}
}

void print_score_arr(int* korean, int* english, int* math, int length) {
	printf("국어\t영어\t수학\n");

	for(int i = 0; i < length; i++) {
		printf("%d\t%d\t%d\n", korean[i], english[i], math[i]);
	}
}

void copy_arr(int* source, int* dist, int length) {
	for(int i = 0; i < length; i++) {
		dist[i] = source[i];
	}
}
	
