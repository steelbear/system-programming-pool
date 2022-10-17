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

Node* db_read_book_list(void) {
	Node* list = NULL;
	Node* node = NULL;
	Book* book = (Book*)malloc(sizeof(Book));
	size_t index = 0;
	int len = 0;
	int ret;

	lseek(fd, sizeof(Book), SEEK_SET);
	while((ret = read(fd, (char*)book, sizeof(Book))) == sizeof(Book)) {
		if (book->id - DB_BASE == index) {
			node = create_node(book);
			push_list(&list, len++, node);
			book = (Book*)malloc(sizeof(Book));
		}
		lseek(fd, (++index) * sizeof(Book), SEEK_SET); 
	}
	free(book);

	return list;
}

void db_write_book(const Book* book) {
	if (book == NULL) {
		fprintf(stderr, "write_book: book이 NULL입니다.\n");	
		return;
	}

	int index = book->id - DB_BASE;
	
	lseek(fd, index * sizeof(Book), SEEK_SET);
}

int db_check_book_by_id(const int id) {
	int index = id - DB_BASE;
	int ret;
	int book_id;

	lseek(fd, index * sizeof(Book), SEEK_SET);
	ret = read(fd, &book_id, sizeof(int));
	
	return ret == sizeof(int) && book_id == id;
}

int db_remove_book_by_id(const int id) {
	int index = id - DB_BASE;
	lseek(fd, index * sizeof(Book), SEEK_SET);
	write(fd, (char*)&BOOK_EMPTY, sizeof(Book)); 
	return 1;
}
