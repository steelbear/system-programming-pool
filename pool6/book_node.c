#include "book_node.h"

Node* create_node(Book* book) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->book = book;
	node->next = NULL;

	return node;
}

Node* pop_node(Node* head, const int id) {
	Node* node = head;
	Node* poped;
	
	if (head == NULL) {
		fprintf(stderr, "get_node_from_list: head가 NULL 입니다.\n");
		return NULL;
	}

	while (node->next != NULL) {
		if (node->next->book->id == id) {
			poped = node->next;
			node->next = poped->next;
			poped->next = NULL;
			return poped;
		}
		node = node->next;
	}

	return NULL;
}

void print_list(Node* head) {
	if (head == NULL) {
		fprintf(stderr, "print_list: 리스트가 NULL입니다.\n");
		return;
	}

	if (head->next == NULL) {
		printf("저장된 책 정보가 없습니다.\n");
		return;
	}

	for (Node* node = head->next; node != NULL; node = node->next) {
		print_book(node->book);
	}
}

void push_node_sorted_by_id(Node* head, Node* node) {
	Node* dest_p = head;
	while (dest_p->next != NULL) {
		if (compare_book_by_id(node->book, dest_p->next->book) < 0) {
			break;
		}
		dest_p = dest_p->next;
	}

	node->next = dest_p->next;
	dest_p->next = node;
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

void copy_and_sort_by_title(Node* dest, Node* src) {
	Node* src_p = src;
	Node* dest_p;
	Node* copied;

	while (src_p->next != NULL) {
		src_p = src_p->next;
		copied = create_node(src_p->book);
		push_node_sorted_by_title(dest, copied);
	}
}

int search_book_by_title(Node* head, char keyword[TITLE_MAX]) {
	Node* node = head;
	int count = 0;

	if (keyword == NULL || head == NULL) {
		fprintf(stderr, "search_book_by_title: keyword 또는 head가 NULL입니다.\n");
		return 0;
	}

	while (node->next != NULL) {
		node = node->next;
		if (substr_book(node->book, keyword)) {
			print_book(node->book);
			++count;
		}
	}

	return count;
}