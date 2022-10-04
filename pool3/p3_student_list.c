#include "p3_student_list.h"


#ifndef P3STUDENTLIST
#define P3STUDENTLIST
StudentNode* create_student_node(Student* student) {
	if (student == NULL) {
		printf("추가할 학생이 존재하지 않습니다.\n");
		return 0;
	}
	
	StudentNode* node = (StudentNode*)malloc(sizeof(StudentNode));
	node->student = student;
	node->next = NULL;

	return node;
}

void delete_student_node(StudentNode* node) {
	if (node == NULL) {
		printf("삭제할 학생이 존재하지 않습니다.\n");
		return;
	}
	
	if (node->student != NULL) {
		delete_student(node->student);
	}

	free(node);
}

void push_node_to_list(StudentNode* node, StudentNode** list) {
	if (list == NULL) {
		printf("노드를 추가할 리스트가 존재하지 않습니다.\n");
		return;
	}

	if (*list == NULL) {
		*list = node;
		(*list)->next = NULL;
	} else {
		node->next = *list;
		*list = node;
	}
}

void delete_node_by_number(int student_number, StudentNode** list) {
	if (list == NULL || *list == NULL) {
		printf("학생이 리스트에 존재하지 않습니다.\n");
		return;
	}

	if (!validate_student_number) {
		return;
	}
	
	StudentNode* node = *list;
	StudentNode* prev_node = NULL;
	
	while (node != NULL && node->student->student_number != student_number) {
		prev_node = node;
		node = node->next;
	}

	if (node == NULL) {
		printf("%d 학번을 가진 학생이 없습니다.\n", student_number); 
		return;
	}

	if (prev_node == NULL) {
		*list = node->next;
	} else {
		prev_node->next = node->next;
	}
	
	delete_student_node(node);
}

void update_student_tel_by_number(int student_number, char* tel, StudentNode* list) {
	if (list == NULL) {
		printf("학생이 리스트에 존재하지 않습니다,\n");
		return;
	}

	if (!validate_student_number(student_number) || !validate_tel(tel)) {
		return;
	}
		
	for (StudentNode* node = list; node != NULL; node = node->next) {
		if (node->student->student_number == student_number) {
			strcpy(node->student->tel, tel);
			return;
		}
	}

	printf("%d 학번을 가진 학생이 존재하지 않습니다.\n", student_number);
}

void update_student_degree_by_number(int student_number, float degree, StudentNode* list) {
	if (list == NULL) {
		printf("학생이 리스트에 존재하지 않습니다.\n");
		return;
	}

	if (!validate_student_number(student_number) || !validate_degree(degree)) {
		return;
	}

	for (StudentNode* node = list; node != NULL; node = node->next) {
		if (node->student->student_number == student_number) {
			node->student->degree = degree;
			return;
		}
	}

	printf("%d 학번을 가진 학생이 존재하지 않습니다.\n", student_number);
}

void print_student_list(StudentNode* list) {
	if (list == NULL) {
		printf("학생이 리스트에 존재하지 않습니다.\n");
		return;
	}

	for (StudentNode* node = list; node != NULL; node = node->next) {
		print_student(node->student);
		if (node->next != NULL) {
			printf("========================\n");
		}
	}
}

void delete_list(StudentNode** list) {
	if (list == NULL || *list == NULL) {
		printf("삭제할 리스트가 없습니다.\n");
		return;
	}

	StudentNode* node = NULL;

	while (*list != NULL) {
		node = *list;
		*list = node->next;
		delete_student_node(node);
	}
}
#endif
