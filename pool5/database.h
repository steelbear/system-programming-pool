#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include "student.h"


int open_db(char* filepath);
int close_db(int fd);
Student* create_student(int std_num, char name[STR_MAX], char addr[STR_MAX], int admission_fee, int birth_year);
int add_student(int fd, Student* student);
Student* search_student_by_name(int fd, char name[STR_MAX]);
void show_student(Student* student);
void show_student_list(int fd);
int update_student_by_num(int fd, int std_num, Student* student);
int delete_student(int fd, int std_num);

int does_student_exist(int fd, int std_num);

int validate_std_num(int std_num);
int validate_name(char name[STR_MAX]);
int validate_addr(char addr[STR_MAX]);
int validate_admission_fee(int admission_fee);
int validate_birth_year(int birth_year);
