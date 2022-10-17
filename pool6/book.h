#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITLE_MAX 25 
#define AUTHOR_MAX 11
#define PUBLISH_MAX 8
#define RECOM_MAX 101


typedef struct _Book {
	int id;
	char title[TITLE_MAX];
	char author[AUTHOR_MAX];
	char published[PUBLISH_MAX];
	char recommand[RECOM_MAX];
	int price;
} Book;


void print_book(const Book* book);
Book* create_book(const int id,
		  const char title[TITLE_MAX],
		  const char author[AUTHOR_MAX],
		  const char published[PUBLISH_MAX],
		  const char recommand[RECOM_MAX],
		  const int price
		);
int compare_book_by_id(const Book* b1, const Book* b2);
int compare_book_by_title(const Book* b1, const Book* b2);
void remove_book(Book* book);
int substr_book(const Book* book, const char* keyword);

