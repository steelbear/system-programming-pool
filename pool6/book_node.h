#include <stdio.h>
#include <stdlib.h>

#include "book.h"

typedef struct _Node {
	Book* book;
	struct _Node* next;
} Node;

Node* create_node(Book* book);
Node* pop_node(Node* head, const int id);
void print_list(Node* head);
void push_node_sorted_by_id(Node* head, Node* node);
void push_node_sorted_by_title(Node* head, Node* node);
void copy_and_sort_by_title(Node* dest, Node* src);
int search_book_by_title(Node* head, char* keyword);