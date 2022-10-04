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


typedef struct _Student {
	int student_number;
	char name[11];
	char birth_year[5];
	char tel[12];
	float degree;
} Student;


Student* create_student(int, char[11], char[5], char[12], float);
void delete_student(Student*);
void print_student(Student*);
int validate_student_number(int);
int validate_name(char[11]);
int validate_birth_year(char[5]);
int validate_tel(char[12]);
int validate_degree(float);
int validate_student_data(int, char[11], char[5], char[12], float);
