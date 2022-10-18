#include "book_db.h"

const Book BOOK_EMPTY = { 0, {""}, {""}, {""}, {""}, 0 };
int fd = -1;

void open_db(const char* file_name) {
	fd = open(file_name, O_RDWR|O_CREAT, 0666);

	if (fd == -1) {
		fprintf(stderr, "open_db: 파일을 열 수 없습니다.\n");
		return;
	}
}

void close_db(void) {
	close(fd);
	fd = -1;
}

void db_read_book_list(Node* head) {
	Node* list = head;
	Node* node = NULL;
	Book* book = (Book*)malloc(sizeof(Book));
	size_t index = 0;
	int len = 0;
	int ret;

	lseek(fd, 0L, SEEK_SET);
	while((ret = read(fd, (char*)book, sizeof(Book))) != 0) {
		if ((book->id - DB_BASE) == index) {
			node = create_node(book);
			push_node_sorted_by_id(list, node);
			list = list->next;
			book = (Book*)malloc(sizeof(Book));
		}
		lseek(fd, (++index) * sizeof(Book), SEEK_SET); 
	}
	free(book);
}

void db_write_book(const Book* book) {
	if (book == NULL) {
		fprintf(stderr, "write_book: book이 NULL입니다.\n");	
		return;
	}

	int index = book->id - DB_BASE;
	
	lseek(fd, index * sizeof(Book), SEEK_SET);
	write(fd, (char*)book, sizeof(Book));
}

int db_check_book_by_id(const int id) {
	int index = id - DB_BASE;
	int ret;
	int book_id;

	lseek(fd, index * sizeof(Book), SEEK_SET);
	ret = read(fd, &book_id, sizeof(int));
	
	return ret == sizeof(int) && book_id == id;
}

Book* db_get_book_by_id(const int id) {
	int index = id - DB_BASE;
	int ret;
	Book* book = (Book*)malloc(sizeof(Book));

	lseek(fd, index * sizeof(Book), SEEK_SET);
	ret = read(fd, (char*)book, sizeof(Book));
	
	if (ret == 0) {
		return NULL;
	} else {
		return book;
	}
}

int db_remove_book_by_id(const int id) {
	int index = id - DB_BASE;
	lseek(fd, index * sizeof(Book), SEEK_SET);
	write(fd, (char*)&BOOK_EMPTY, sizeof(Book)); 
	return 1;
}
