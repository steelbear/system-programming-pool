#include <fcntl.h>
#include <unistd.h>

#include "book_node.h"

#define DB_BASE 1


void open_db(const char* file_name);
void close_db(void);
void db_read_book_list(Node* head);
void db_write_book(const Book* book);
int db_check_book_by_id(const int id);
Book* db_get_book_by_id(const int id);
void db_remove_book_by_id(const int id);
