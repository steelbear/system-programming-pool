#ifndef STDIO
#include <stdio.h>
#define STDIO
#endif

#ifndef STDLIB
#include <stdlib.h>
#define STDLIB
#endif

#ifndef STRING
#include <string.h>
#define STRING
#endif

#include "p3_student.h"


typedef struct _StudentNode {
	Student* student;
	struct _StudentNode* next;
} StudentNode;

StudentNode* create_student_node(Student*);
void delete_student_node(StudentNode*);
void push_node_to_list(StudentNode*, StudentNode**);
void delete_node_by_number(int, StudentNode**);
void update_student_tel_by_number(int, char*, StudentNode*);
void update_student_degree_by_number(int, float, StudentNode*);
void print_student_list(StudentNode*);
void delete_list(StudentNode**);
