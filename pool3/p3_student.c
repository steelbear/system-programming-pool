#include "p3_student.h"

typedef struct Student {
	int student_number;
	char* name;
	char* birth_year;
	char* tel;
	float degree;
} Student;

Student* create_student(int student_number, char* name, char* birth_year, char* tel, float degree) {
	Student* new_student = NULL;
	
	if (validate_student_data(student_number, name, birth_year, tel, degree)) {
		new_student = (Student*)malloc(sizeof(Student));
		new_student->student_number = student_number;
		new_student->name = name;
		new_student->birth_year = birth_year;
		new_student->tel = tel;
		new_student->degree = degree;
	}	

	return new_student;
}

int validate_student_data(int student_number, char* name, char* birth_year, char* tel, float degree) {
	return student_number >= 0 &&
		name != NULL &&
		sizeof(name) > 0 &&
		
