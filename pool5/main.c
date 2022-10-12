#include <stdio_ext.h>
#include "database.h"


void add_student_io(int fd) {
	int flag;
	int std_num;
	do {
		printf("학번: ");
		scanf("%d", &std_num);
		__fpurge(stdin);

		if (flag = does_student_exist(fd, std_num)) {
			printf("이미 존재합니다\n");
		}
	} while (flag || !validate_std_num(std_num));

	char name[STR_MAX];
	do {
		printf("이름: ");
		scanf("%s", name);
		__fpurge(stdin);
	} while (!validate_name(name));

	char addr[STR_MAX];
	do {
		printf("주소: ");
		scanf("%s", addr);
		__fpurge(stdin);
	} while (!validate_addr(addr));

	int admission_fee;
	do {
		printf("학비: ");
		scanf("%d", &admission_fee);
		__fpurge(stdin);
	} while (!validate_admission_fee(admission_fee));

	int birth_year;
	do {
		printf("생년: ");
		scanf("%d", &birth_year);
		__fpurge(stdin);
	} while (!validate_birth_year(birth_year));

	Student* student = create_student(std_num, name, addr, admission_fee, birth_year);
	add_student(fd, student);
}

void search_student_by_name_io(int fd) {
	char name[STR_MAX];

	do {
		printf("이름: ");
		scanf("%s", name);
		__fpurge(stdin);
	} while (!validate_name(name));

	Student* student = search_student_by_name(fd, name);
	
	if (student != NULL) {
		show_student(student);
	}
}

void update_student_by_num_io(int fd) {
	int flag;
	int std_num;
	do {
		printf("학번: ");
		scanf("%d", &std_num);
		__fpurge(stdin);
		if (flag = !does_student_exist(fd, std_num)) {
			printf("%d 학번을 가진 학생이 없습니다.\n", std_num);
		}	
	} while (flag || !validate_std_num(std_num));

	char name[STR_MAX];
	do {
		printf("이름: ");
		scanf("%s", name);
		__fpurge(stdin);
	} while (!validate_name(name));

	char addr[STR_MAX];
	do {
		printf("주소: ");
		scanf("%s", addr);
		__fpurge(stdin);
	} while (!validate_addr(addr));

	int admission_fee;
	do {
		printf("학비: ");
		scanf("%d", &admission_fee);
		__fpurge(stdin);
	} while (!validate_admission_fee(admission_fee));

	int birth_year;
	do {
		printf("생년: ");
		scanf("%d", &birth_year);
		__fpurge(stdin);
	} while (!validate_birth_year(birth_year));
	
	Student* student = create_student(std_num, name, addr, admission_fee, birth_year);
	update_student_by_num(fd, std_num, student);
}

void delete_student_io(int fd) {
	int flag;
	int std_num;

	do {
		printf("학번: ");
		scanf("%d", &std_num);
		__fpurge(stdin);
		if (flag = !does_student_exist(fd, std_num)) {
			printf("%d 학번을 가진 학생이 없습니다.\n", std_num);
		}
	} while (flag || !validate_std_num(std_num));
	
	delete_student(fd, std_num);
}

void print_prompt() {
	printf("1) 학생 입력\n2) 전체 학생 리스트\n3) 이름으로 검색\n4) 학생 정보 수정\n5) 학생 삭제\n0) 종료\n 입력: ");
}

int main() {
	int fd = open_db("student.db");

	if (fd == -1) {
		exit(1);
	}

	int input = -1;
	while (input != 0) {
		print_prompt();
		scanf("%d", &input);
		__fpurge(stdin);

		switch(input) {
			case 1:
				add_student_io(fd);
				break;
			case 2:
				show_student_list(fd);
				break;
			case 3:
				search_student_by_name_io(fd);
				break;
			case 4:
				update_student_by_num_io(fd);
				break;
			case 5:
				delete_student_io(fd);
				break;
			case 0:
				printf("학생 정보 관리 프로그램을 종료합니다.\n");
				break;
			default:
				printf("잘못 입력하셨습니다. 다시 입력해주세요.\n");
				break;
		}
	}

	close_db(fd);
	return 0;
}
