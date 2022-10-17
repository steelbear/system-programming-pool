#include <stdio.h>
#include <stdlib.h>

#include "book.h"

typedef struct _Node {
	Book* book;
	struct _Node* next;
} Node;

Node* create_node(Book* book);
void remove_node(Node* node);
void push_list(Node** list, const int index, Node* node); 
Node* pop_list(Node** list, const int index);
void print_list(Node** list);

