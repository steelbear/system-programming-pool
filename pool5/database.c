#include "database.h"

int open_db(char* filepath) {
	if (filepath == NULL) {
		printf("불러올 파일 경로를 입력하세요.\n");
		return -1;
	}

	int fd = open(filepath, O_RDWR|O_CREAT|O_SYNC, 0666);

	if (fd == -1) {
		printf("데이터베이스에 연결하는데 문제가 발생했습니다.\n");
		return -1;
	}

	return fd;
}

int close_db(int fd) {
	return close(fd);
}

Student* create_student(int std_num, char name[STR_MAX], char addr[STR_MAX], int admission_fee, int birth_year) {
	int validation = 1;
	validation &= validate_std_num(std_num);
	validation &= validate_name(name);
	validation &= validate_addr(addr);
	validation &= validate_admission_fee(admission_fee);
	validation &= validate_birth_year(birth_year);

	if (!validation) {
		return NULL;
	}	
	
	Student* new_student = (Student*)malloc(sizeof(Student));
	new_student->std_num = std_num;
	strcpy(new_student->name, name);
	strcpy(new_student->addr, addr);
	new_student->admission_fee = admission_fee;
	new_student->birth_year = birth_year;
	
	return new_student;
}

int add_student(int fd, Student* student) {
	if (fd == -1) {
		printf("데이터베이스에 연결되어있지 않습니다.\n");
		return -1;
	}

	if (student == NULL) {
		printf("추가할 학생이 없습니다.\n");
		return -1;
	}

	if (does_student_exist(fd, student->std_num)) {
		printf("이미 %d 학번을 가진 학생이 있습니다.\n", student->std_num);
		return -1;
	}

	int index = student->std_num - 1;
	lseek(fd, index * sizeof(Student), SEEK_SET);
	int result = write(fd, (char*)student, sizeof(Student));

	if (result == -1) {
		printf("학생을 데이터베이스에 추가하는데 실패했습니다.\n");
	}

	return result;
}

Student* search_student_by_name(int fd, char name[STR_MAX]) {
	if (fd == -1) {
		printf("데이터베이스에 연결되어있지 않습니다.\n");
		return NULL;
	}

	if (!validate_name(name)) {
		return NULL;
	}

	Student* student = (Student*)malloc(sizeof(Student));
	for (int i = 0; ;++i) {
		lseek(fd, i * sizeof(Student), SEEK_SET);
		if (read(fd, (char*)student, sizeof(Student)) == 0) {
			break;
		}
		if (strcmp(name, student->name) == 0) {
			return student;
		}
	}

	printf("%s 이름을 가진 학생이 없습니다.\n", student->name);
	return NULL;
}

void show_student(Student* student) {
	printf("학번: %d\n이름: %s\n주소: %s\n학비: %d\n생년: %d\n",
			student->std_num,
			student->name,
			student->addr,
			student->admission_fee,
			student->birth_year
	      );
}

void show_student_list(int fd) {
	Student* student = (Student*)malloc(sizeof(Student));
	
	for(int i = 0; ; ++i) {
		lseek(fd, i * sizeof(Student), SEEK_SET);
		if (read(fd, (char*)student, sizeof(Student)) == 0) {
			break;
		}

		if (student->std_num == i + 1) {
			show_student(student);
			printf("*******************\n");
		}
	}
}

int update_student_by_num(int fd, int std_num, Student* student) {
	if (fd == -1) {
		printf("데이터베이스에 연결되어있지 않습니다.\n");
		return -1;
	}

	if (student == NULL) {
		printf("변경할 학생의 데이터가 없습니다.\n");
		return -1;
	}

	if (!does_student_exist(fd, student->std_num)) {
		printf("%d 학번을 가진 학생이 없습니다.\n", std_num);
		return -1;
	}

	int index = std_num - 1;
	lseek(fd, index * sizeof(Student), SEEK_SET);
	int result = write(fd, (char*)student, sizeof(Student));

	if (result == -1) {
		printf("학생 데이터를 데이터베이스에서 수정하는데 실패했습니다.\n");
	}

	return result;
}

int delete_student(int fd, int std_num) {
	Student STD_EMPTY = {0, {""}, {""}, 0, 0};
	if (fd == -1) {
		printf("데이터베이스에 연결되어있지 않습니다.\n");
		return -1;
	}

	if (!validate_std_num(std_num)) {
		return 0;
	}
	
	int index = std_num - 1;
	lseek(fd, index * sizeof(Student), SEEK_SET);

	int seek_std_num;
	read(fd, &seek_std_num, sizeof(int));

	if (seek_std_num == std_num) {
		lseek(fd, index * sizeof(Student), SEEK_SET);

		int result = write(fd, &STD_EMPTY, sizeof(Student));
		if (result == -1) {
			printf("학생을 데이터베이스에서 삭제하는데 실패했습니다.\n");
		}

		return result;
	} else {
		printf("%d 학번을 가진 학생이 없습니다.\n", std_num);

		return -1;
	}
}

int does_student_exist(int fd, int std_num) {
	if (fd <= 2) {
		printf("데이터베이스에 연결되어 있지 않습니다.\n");
		return 0;
	}

	if (!validate_std_num(std_num)) {
		return 0;
	}

	int index = std_num - 1;
	lseek(fd, index * sizeof(Student), SEEK_SET);

	int seek_std_num;
       	int result = read(fd, &seek_std_num, sizeof(int));
	if (result < 0) {
		printf("데이터베이스에서 불러오는데 실패했습니다,\n");
		return 0;
	}

	return std_num == seek_std_num;
}

int validate_std_num(int std_num) {
	if (std_num <= 0) {
		printf("1 이상의 정수를 입력하세요.\n");
		return 0;
	}

	return 1;
}

int validate_name(char name[STR_MAX]) {
	if (name == NULL) {
		printf("이름을 입력해주세요.\n");
		return 0;
	}

	for (int i = 0; i < STR_MAX; ++i) {
		if (name[i] == '\0') {
			return 1;
		}
	}

	printf("이름을 입력해주세요.\n");
	return 0;
}

int validate_addr(char addr[STR_MAX]) {
	if (addr == NULL) {
		printf("주소를 입력해주세요.\n");
		return 0;
	}

	for (int i = 0; i < STR_MAX; ++i) {
		if (addr[i] == '\0') {
			return 1;
		}
	}

	printf("주소를 입력해주세요.\n");
	return 0;
}

int validate_admission_fee(int admission_fee) {
	if (admission_fee < 0) {
		printf("양의 정수를 입력해주세요.\n");
		return 0;
	}

	return 1;
}

int validate_birth_year(int birth_year) {
	if (birth_year < 1900 || birth_year > 9999) {
		printf("1900이상의 4자리 숫자를 입력해주세요.\n");
		return 0;
	}

	return 1;
}
