#include "book_node.h"

Node* create_node(Book* book) {
	if (book == NULL) {
		fprintf(stderr, "create_node: book이 NULL입니다.\n");
		return NULL;
	}

	Node* node = (Node*)malloc(sizeof(Node));
	node->book = book;
	node->next = NULL;

	return node;
}

void remove_node(Node* node) {
	remove_book(node->book);
	free(node);
}

void push_list(Node* head, const int index, Node* node) {
	Node* cur = head;
	int i = 0;
	
	if (head == NULL) {
		fprintf(stderr, "pop_list: 리스트가 NULL입니다.\n");
		return;
	}

	while (cur->next != NULL) {
		if (i == index) break;
		cur = cur->next;
		++i;
	}

	if (i < index) {
		fprintf(stderr, "push_list: %d 길이의 리스트에서 %d에 접근하려 합니다.\n", index, i);
		return;
	}

	node->next = cur->next;
	cur->next = node;
}

Node* pop_list(Node* head, const int index) {
	Node* cur = head;
	Node* poped = NULL;
	int i = 0;

	if (head == NULL) {
		fprintf(stderr, "pop_list: 리스트가 NULL입니다.\n");
		return NULL;
	}

	while (cur->next != NULL) {
		if (i == index) break;
		cur = cur->next;
		++i;
	}

	if (i < index) {
		fprintf(stderr, "pop_list: %d 길이의 리스트에서 %d에 접근하려 합니다.\n", index, i);
		return NULL;
	}

	poped = cur->next;
	cur->next = cur->next->next;
	poped->next = NULL;
	return poped;
}

void print_list(Node* head) {
	if (head == NULL) {
		fprintf(stderr, "print_list: 리스트가 NULL입니다.\n");
		return;
	}

	if (head->next == NULL) {
		printf("저장된 책 정보가 없습니다.\n");
	}

	printf("%8s %24s %10s %8s %s\n", "식별자", "도서명", "저자명", "출판", "가격");

	for (Node* node = head->next; node != NULL; node = node->next) {
		print_book(node->book);
	}
}

void push_node_sorted_by_title(Node* head, Node* node) {
	Node* dest_p = head;
	while (dest_p->next != NULL) {
		if (compare_book_by_title(node->book, dest_p->next->book) < 0) {
			break;
		}
		dest_p = dest_p->next;
	}

	node->next = dest_p->next;
	dest_p->next = node;
}

void copy_and_sort_by_title(Node* dest, const Node* src) {
	Node* src_p = src;
	Node* dest_p;
	Node* copied;

	while (src_p->next != NULL) {
		src_p = src_p->next;
		copied = create_node(src_p->book);
		push_node_sorted_by_title(dest, copied);
	}
}

void remove_list(Node* head) {
	Node* node = head->next;
	Node* removed;

	while (node != NULL) {
		removed = node;
		node = node->next;
		remove_node(removed);
	}
	head->next = NULL;
}