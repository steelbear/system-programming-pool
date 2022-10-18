#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

#include "book_db.h"

void repl(Node* head_id, Node* head_title);
void clearning(Node* head_id, Node* head_title);
void print_prompt(void);
void run(const int input, Node* head_id, Node* head_title);
void list_all(Node* head);
void add_book(Node* head_id, Node* head_title);
void update_book(Node* head_id, Node* head_title);
void delete_book(Node* head_id, Node* head_title);
void search_book(Node* head);

Book* get_book_info_input(int id);
void remove_shared_book_node(Node* head1, Node* head2, const int id);