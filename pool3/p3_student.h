#ifndef STDIO
#include <stdio.h>
#define STDIO
#endif

#ifndef STDLIB
#include <stdlib.h>
#define STDLIB
#endif


typedef struct _Student {
	int student_number;
	char* name;
	char* birth_year;
	char* tel;
	float degree;
} Student;


Student* create_student(int, char*, char*, char*, float);
void delete_student(Student*);
void print_student(Student*);
int validate_student_number(int);
int validate_name(char*);
int validate_birth_year(char*);
int validate_tel(char*);
int validate_degree(float);
int validate_student_data(int, char*, char*, char*, float);
