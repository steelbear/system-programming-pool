#include "book.h"

void print_book(const Book* book) {
	if (book == NULL) {
		fprintf(stderr, "print_book: 표시할 책이 NULL입니다.\n");
		return;
	}

	printf(" 식별자: %d\n 제목: %s\n 저자: %s\n 출판년월일: %s\n 가격: %d원\n 추천 이유: %s\n",
			book->id,
			book->title,
			book->author,
			book->published,
			book->price,
			book->recommand
	);
}

Book* create_book(const int id,
		  const char title[TITLE_MAX],
		  const char author[AUTHOR_MAX],
		  const char published[PUBLISH_MAX],
		  const char recommand[RECOM_MAX],
		  const int price) {
	Book* book = (Book*)malloc(sizeof(Book));

	book->id = id;
	strcpy(book->title, title);
	strcpy(book->author, author);
	strcpy(book->published, published);
	strcpy(book->recommand, recommand);
	book->price = price;

	return book;
}

int compare_book_by_id(const Book* b1, const Book* b2) {
	if (b1 == NULL || b2 == NULL) {
		fprintf(stderr, "compare_book_by_id: b1과 b2 둘 중 하나가 NULL입니다.\n");
		return 0;
	}

	return (b1->id)-(b2->id);
}

int compare_book_by_title(const Book* b1, const Book* b2) {
	if (b1 == NULL || b2 == NULL) {
		fprintf(stderr, "compare_book_by_id: b1과 b2 둘 중 하나가 NULL입니다.\n");
		return 0;
	}

	return strcmp(b1->title, b2->title);
}

void remove_book(Book* book) {
	if (book == NULL) {
		fprintf(stderr, "remove_book: 삭제할 책이 NULL입니다.\n");
		return;
	}
	free(book);
}

int substr_book(const Book* book, const char* keyword) {
	if (book == NULL || keyword == NULL) {
		fprintf(stderr, "substr_book: book 또는 keyword가 NULL입니다.\n");
		return 0;
	}

	return (int)(*strstr(book->title, keyword));
}
