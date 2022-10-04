#include "p3_student.h"

#ifndef P3STUDENT
#define P3STUDENT
Student* create_student(int student_number, char name[11], char birth_year[5], char tel[12], float degree) {
	Student* new_student = NULL;
	
	if (validate_student_data(student_number, name, birth_year, tel, degree)) {
		new_student = (Student*)malloc(sizeof(Student));
		new_student->student_number = student_number;
		strcpy(new_student->name, name);
		strcpy(new_student->birth_year, birth_year);
		strcpy(new_student->tel, tel);
		new_student->degree = degree;
	}	

	return new_student;
}

void delete_student(Student* student) {
	if (student == NULL) {
		printf("삭제할 학생이 없습니다.\n");
		return;
	}
	free(student);
}

void print_student(Student* student) {
	printf("학번: %d\n이름: %s\n생년: %s\n전화번호: %s\n학점: %.2f\n",
			student->student_number,
			student->name,
			student->birth_year,
			student->tel,
			student->degree);
}

int validate_student_number(int student_number) {
	if (student_number <= 0) {
		printf("학번이 올바르지 않습니다.\n");
		return 0;
	}
	return 1;
}

int validate_name(char name[11]) {
	if (name == NULL) {
		printf("이름이 올바르지 않습니다.\n");
		return 0;
	}
	for (int i = 0; i < 11; i++) {
		if (name[i] == '\0') {
			return 1;
		}
	}
	printf("이름을 입력해주세요.\n");
	return 0;
}

int validate_birth_year(char birth_year[5]) {
	if (birth_year == NULL) {
		printf("생년이 올바르지 않습니다.\n");
		return 0;
	}
	for (int i = 0; i < 4; ++i) {
		if (birth_year[i] == '\0') {
			printf("생년은 4자리 수 입니다.\n");
			return 0;
		}
	}
	if (birth_year[4] != '\0') {
		printf("생년은 4자리 수 입니다.\n");
		return 0;
	}
	for (int i = 0; i < 4; ++i) {
		if (birth_year[i] < '0' || '9' < birth_year[i]) {
			printf("생년은 숫자로 입력해야 합니다.\n");
			return 0;
		}
	}
	return 1;
}

int validate_tel(char tel[12]) {
	if (tel == NULL) {
		printf("전화번호가 올바르지 않습니다.\n");
		return 0;
	}
	for (int i = 0; i < 11; ++i) {
		if (tel[i] == '\0') {
			printf("전화번호는 11자리 수 입니다.\n");
			return 0;
		}
	}
	if (tel[11] != '\0') {
		printf("전화번호는 11자리 수 입니다.\n");
		return 0;
	}
	for (int i = 0; i < 11; ++i) {
		if (tel[i] < '0' || '9' < tel[i]) {
			printf("전화번호는 숫자로 입력해야 합니다.\n");
			return 0;
		}
	}
	return 1;
}

int validate_degree(float degree) {
	if (degree < 0.0 || 4.5 < degree) {
		printf("학점은 0.0~4.5 사이여야 합니다.\n");
		return 0;
	}
	return 1;
}

int validate_student_data(int student_number, char* name, char* birth_year, char* tel, float degree) {
	return validate_student_number(student_number)
		&& validate_name(name)
		&& validate_birth_year(birth_year)
		&& validate_tel(tel)
		&& validate_degree(degree);
}
#endif
