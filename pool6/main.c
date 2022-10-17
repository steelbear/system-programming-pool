#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

#include "book_db.h"


void print_prompt(void);
void run(const int input, Node* head_id, Node* head_title);
void list_all(Node* head);

int main(void) {
	int input = -1;
	Node* head_id = create_node(NULL);
	Node* head_title = create_node(NULL);

	open_db("Book_steelbear.dbx");
	db_read_book_list(head_id);
	copy_and_sort_by_title(head_title, head_id);

	while (input != 0) {
		print_prompt();
		scanf("%d", &input);
		__fpurge(stdin);
		run(input, head_id, head_title);
	}

	return 0;
}

void print_prompt(void) {
	printf("Book Management\n 1. List up All Book(Sort by 식별자)\n 2. List up All Book(Sort by 도서명)\n 3. Add New Book\n 4. Update Book\n 5. Remove a Book\n 6. Search Book Information By Title(minimum 2char)\n 0. Quit\n입력: ");
}

void run(const int input, Node* head_id, Node* head_title) {
	switch (input) {
		case 1:
			list_all(head_id);
			break;
		case 2:
			list_all(head_title);
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 0:
			printf("도서 관리 프로그램을 종료합니다.\n");
			break;
		default:
			printf("잘못 입력하셨습니다.\n");
			break;
	}
}

void list_all(Node* head) {
	print_list(head);
}

void add_book(Node* head_id, Node* head_title) {
	int id;
	char title[TITLE_MAX];
	char author[AUTHOR_MAX];
	char published[PUBLISH_MAX];
	char recommand[RECOM_MAX];
	int price;

	do {
		printf("추가할 책의 식별자 : ");
		scanf("%d", &id);
		__fpurge(stdin);
		if (id < 0 || !db_check_book_by_id(id)) {
			printf("이미 존재하거나 유효하지 않은 식별자입니다.\n");
			break;
		}
	} while (true);
