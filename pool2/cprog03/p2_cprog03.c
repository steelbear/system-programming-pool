#include "p2_cprog03.h"

void p2_cprog03() {
	int input = -1;
	
	int* korean = NULL;
	int* english = NULL;
	int* math = NULL;

	int length;

	while(input != 0) {
		print_p2_cprog03_prompt();
		scanf("%d", &input);
		switch(input) {
			case 1:
				input_arr_not_null(korean, length);
				break;
			case 2:
				input_arr_not_null(english, length);
				break;
			case 3:
				input_arr_not_null(math, length);
				break;
			case 4:
				average_score_not_null(korean, english, math, length);
				break;
			case 5:
				maximum_score_not_null(korean, english, math, length);
				break;
			case 6:
				minimum_score_not_null(korean, english, math, length);
				break;
			case 7:
				argmax_score_not_null(korean, english, math, length);
				break;
			case 8:
				sort_score_not_null(korean, english, math, length);
				break;
			case 9:
				length = create_score_arr(&korean, &english, &math);
				break;
			case 0:
				printf("학생 성적 프로그램을 종료합니다.\n");
				break;
			default:
				printf("잘못 입력하셨습니다. 다시 입력해주세요.\n");
				break;
		}
	}
}


void print_p2_cprog03_prompt() {
	printf(" 9. 반 학생의 수 입력\n 1. 국어성적 입력\n 2. 영어성적 입력\n 3. 수학성적 입력\n 4. 각 과목의 평균\n 5. 각 과목의 최고점\n 6. 각 과목의 최저점\n 7. 각 과목의 최고점수 학생번호\n 8. 각 과목의 점수 오름차순\n 0. 종료\n입력 : ");
}


void sort_score(int* korean, int* english, int* math, int length) {
	if (korean[0] == -1 || english[0] == -1 || math[0] == -1) {
		printf("모든 과목의 성적을 입력하세요.\n");
		return;
	}

	int* sorted_korean = (int*)malloc(sizeof(int) * length);
	int* sorted_english = (int*)malloc(sizeof(int) * length);
	int* sorted_math = (int*)malloc(sizeof(int) * length);

	copy_arr(korean, sorted_korean, length);
	copy_arr(english, sorted_english, length);
	copy_arr(math, sorted_math, length);

	sort_arr(sorted_korean, length);
	sort_arr(sorted_english, length);
	sort_arr(sorted_math, length);

	print_score_arr(sorted_korean, sorted_english, sorted_math, length);
}

int create_score_arr(int** korean, int** english, int** math) {
	int length = 0;

	while (length <= 0) {
		printf("학생 수 입력 : ");
		scanf("%d", &length);
		if (length <= 0) {
			printf("양의 정수를 입력해 주세요.\n");
		}
	}

	*korean = (int*)malloc(sizeof(int) * length);
	*english = (int*)malloc(sizeof(int) * length);
	*math = (int*)malloc(sizeof(int) * length);

	(*korean)[0] = -1;
	(*english)[0] = -1;
	(*math)[0] = -1;

	return length;
}

void input_arr_not_null(int* arr, int length) {
	if (arr != NULL) {
		input_arr(arr, length);
	} else {
		printf("학생 수를 먼저 입력해주세요.\n");
	}
}

void average_score_not_null(int* korean, int* english, int* math, int length) {
	if (korean != NULL && english != NULL && math != NULL) {
		average_score(korean, english, math, length);
	} else {
		printf("학생 수를 먼저 입력해주세요.\n");
	}	
}


void maximum_score_not_null(int* korean, int* english, int* math, int length) {
	if (korean != NULL && english != NULL && math != NULL) {
		maximum_score(korean, english, math, length);
	} else {
		printf("학생 수를 먼저 입력해주세요.\n");
	}	
}

void minimum_score_not_null(int* korean, int* english, int* math, int length) {
	if (korean != NULL && english != NULL && math != NULL) {
		minimum_score(korean, english, math, length);
	} else {
		printf("학생 수를 먼저 입력해주세요.\n");
	}	
}

void argmax_score_not_null(int* korean, int* english, int* math, int length) {
	if (korean != NULL && english != NULL && math != NULL) {
		argmax_score(korean, english, math, length);
	} else {
		printf("학생 수를 먼저 입력해주세요.\n");
	}	
}

void sort_score_not_null(int* korean, int* english, int* math, int length) {
	if (korean != NULL && english != NULL && math != NULL) {
		sort_score(korean, english, math, length);
	} else {
		printf("학생 수를 먼저 입력해주세요.\n");
	}	
}
