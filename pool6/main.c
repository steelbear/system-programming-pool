#include "main.h"

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
			add_book(head_id, head_title);
			break;
		case 4:
			update_book(head_id, head_title);
			break;
		case 5:
			delete_book(head_id, head_title);
			break;
		case 6:
			search_book(head_title);
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
	Book* book;
	Node* id_node;
	Node* title_node;
	int id;

	printf("추가할 책의 식별자: ");
	scanf("%d", &id);
	__fpurge(stdin);
	if (id <= 0 || db_check_book_by_id(id)) {
		printf("이미 존재하거나 유효하지 않은 식별자입니다.\n");
		return;
	}

	book = get_book_info_input(id);
	if (book == NULL) return;
	print_book(book);
	id_node = create_node(book);
	title_node = create_node(book);

	push_node_sorted_by_id(head_id, id_node);
	push_node_sorted_by_title(head_title, title_node);
	db_write_book(book);
}

void update_book(Node* head_id, Node* head_title) {
	Book* book;
	Node* id_node;
	Node* title_node;
	int id;

	printf("수정할 책의 식별자: ");
	scanf("%d", &id);
	__fpurge(stdin);

	if (!db_check_book_by_id(id)) {
		printf("%d 식별자를 가진 책이 없습니다.\n", id);
		return;
	}

	book = db_get_book_by_id(id);
	printf("기존 데이터\n");
	print_book(book);
	remove_book(book);

	book = get_book_info_input(id);
	if (book == NULL) return;
	print_book(book);
	id_node = create_node(book);
	title_node = create_node(book);

	remove_shared_book_node(head_id, head_title, id);
	push_node_sorted_by_id(head_id, id_node);
	push_node_sorted_by_title(head_title, title_node);
	db_write_book(book);
}

void delete_book(Node* head_id, Node* head_title) {
	Book* book;
	Node* id_node;
	Node* title_node;
	int id;

	printf("삭제할 책의 식별자: ");
	scanf("%d", &id);
	__fpurge(stdin);

	if (!db_check_book_by_id(id)) {
		printf("%d 식별자를 가진 책이 없습니다.\n", id);
		return;
	}

	remove_shared_book_node(head_id, head_title, id);
	db_remove_book_by_id(id);
}

void search_book(Node* head) {
	char keyword[TITLE_MAX];
	int count;

	if (head == NULL || head->next == NULL) {
		printf("저장된 책 정보가 없습니다.\n");
		return;
	}
	
	while (1) {
		printf("검색어: ");
		scanf("%24s", keyword);
		if (keyword[0] && keyword[1]) {
			break;
		}
		printf("두글자 이상 입력하세요,\n");
	}
	

	count = search_book_by_title(head, keyword);
	if (count == 0) {
		printf("%s 검색어에 해당하는 책이 없습니다.\n", keyword);
	}
}

Book* get_book_info_input(int id) {
	char title[TITLE_MAX];
	char author[AUTHOR_MAX];
	char published[PUBLISH_MAX];
	char recommand[RECOM_MAX];
	int price;

	do {
		printf("항목에 맞게 입력하세요.\n");
		printf("%s\t%s\t%s\t%s\n", "도서명", "저자명", "출판일(YYYYMMdd)", "가격");
		scanf("%24s %20s %8s %d", title, author, published, &price);
		__fpurge(stdin);
	} while(price <= 0);

	printf("해당 책의 추천할만한 이유를 적어주세요(100자 이내):\n");
	scanf("%100s", recommand);
	__fpurge(stdin);

	return create_book(id, title, author, published, recommand, price);
}

void remove_shared_book_node(Node* head1, Node* head2, const int id) {
	Node* node1;
	Node* node2;
	Book* shared_book;

	if (head1 == NULL || head2 == NULL) {
		fprintf(stderr, "remove_shared_book_node: head1 또는 head2가 NULL 입니다.\n");
		return;
	}

	node1 = pop_node(head1, id);
	node2 = pop_node(head2, id);
	shared_book = node1->book;
	remove_book(shared_book);
	free(node1);
	free(node2);
}