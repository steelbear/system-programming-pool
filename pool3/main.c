#include <stdio.h>
#include <stdio_ext.h>
#include "p3_student_list.h"


void print_p3_prompt();
int set_num_student();
void input_student(StudentNode**);
void input_student_all(StudentNode**, int);
void update_tel(StudentNode*);
void update_degree(StudentNode*);
void delete_student_by_number(StudentNode**);


int main() {
	int input = -1;
	StudentNode* list = NULL;
	int num_student = 0;

	while (input != 0) {
		print_p3_prompt();
		__fpurge(stdin);
		scanf("%d", &input);
		switch (input) {
			case 1:
				num_student = set_num_student();
				delete_list(&list);
				break;
			case 2:
				input_student_all(&list, num_student);	
				break;
			case 3:
				print_student_list(list);
				break;
			case 4:
				update_tel(list);
				break;
			case 5:
				update_degree(list);
				break;
			case 6:
				input_student(&list);
				++num_student;
				break;
			case 7:
				delete_student_by_number(&list);
				--num_student;
				break;
			case 0:
				printf("학생 관리 프로그램을 종료합니다.\n");
				break;
			default:
				printf("다시 입력해주세요\n");
				break;
		}
	}

	return 0;
}

void print_p3_prompt() {
	printf(" 1. 저장할 학생 명수 입력\n 2. 학생 정보 입력\n 3. 학생 목록 출력\n 4. 학생 정보 수정(핸드폰 번호)\n 5. 학생 정보 수정(학점)\n 6. 학생 정보 추가\n 7. 학생 정보 삭제\n 0. 종료\n 입력 : ");
}

int set_num_student() {
	int num_student = -1;

	while (num_student <= 0) {
		printf("학생 수 입력 : ");
		__fpurge(stdin);
		scanf("%d", &num_student);

		if (num_student <= 0) {
			printf("양수를 입력하세요\n");
		}
	}

	return num_student;
}

void input_student(StudentNode** list) {
	StudentNode* node = NULL;
	Student* student = NULL;
	int student_number;
	char name[11];
	char birth_year[5];
	char tel[12];
	float degree;

	do {
		printf("학번: ");
		__fpurge(stdin);
		scanf("%d", &student_number);
	} while (!validate_student_number(student_number));
	do {
		printf("이름: ");
		__fpurge(stdin);
		scanf("%s", name);
	} while (!validate_name(name));
	do {
		printf("생년(4자리): ");
		__fpurge(stdin);
		scanf("%s", birth_year);
	} while (!validate_birth_year(birth_year));
	do {
		printf("전화번호(-제외): ");
		__fpurge(stdin);
		scanf("%s", tel);
	} while (!validate_tel(tel));
	do {
		printf("학점: ");
		__fpurge(stdin);
		scanf("%f", &degree);
	} while (!validate_degree(degree));

	student = create_student(student_number, name, birth_year, tel, degree);
	node = create_student_node(student);
	push_node_to_list(node, list);
}

void input_student_all(StudentNode** list, int length) {
	if (length <= 0) {
		printf("학생 수를 입력해주세요.\n");
		return;
	}

	if (list == NULL) {
		printf("리스트가 없습니다,\n");
		return;
	}
	if (*list != NULL) {
		delete_list(list);
	}

	for (int i = 0; i < length; ++i) {
		input_student(list);
	}
}

void update_tel(StudentNode* list) {
	if (list == NULL) {
		printf("리스트에 학생이 없습니다.\n");
		return;
	}

	int student_number;
	char* tel;

	do {
		printf("변경할 학생의 학번: ");
		__fpurge(stdin);
		scanf("%d", &student_number);
	} while (!validate_student_number(student_number));

	do {
		printf("전화번호(-제외): ");
		__fpurge(stdin);
		scanf("%s", tel);
	} while (!validate_tel(tel));

	update_student_tel_by_number(student_number, tel, list);
}

void update_degree(StudentNode* list) {
	if (list == NULL) {
		printf("리스트에 학생이 없습니다.\n");
		return;
	}

	int student_number;
	float degree;

	do {
		printf("변경할 학생의 학번: ");
		__fpurge(stdin);
		scanf("%d", &student_number);
	} while (!validate_student_number(student_number));

	do {
		printf("학점: ");
		__fpurge(stdin);
		scanf("%f", &degree);
	} while (!validate_degree(degree));

	update_student_degree_by_number(student_number, degree, list);
}

void delete_student_by_number(StudentNode** list) {
	if (list == NULL || *list == NULL) {
		printf("리스트에 학생이 없습니다.\n");
		return;
	}
	
	int student_number;

	do {
		printf("삭제할 학생의 학번: ");
		__fpurge(stdin);
		scanf("%d", &student_number);
	} while (!validate_student_number(student_number));

	delete_node_by_number(student_number, list);
}
