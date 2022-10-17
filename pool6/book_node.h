#include <stdio.h>
#include <stdlib.h>

#include "book.h"

typedef struct _Node {
	Book* book;
	struct _Node* next;
} Node;

Node* create_node(Book* book);
void remove_node(Node* node);
void push_list(Node* head, const int index, Node* node); 
Node* pop_list(Node* head, const int index);
void print_list(Node* head);
void push_node_sorted_by_title(Node* head, Node* node);
void copy_and_sort_by_title(Node* dest, Node* src);
void remove_list(Node* head);
