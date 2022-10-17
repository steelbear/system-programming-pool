#include <fcntl.h>
#include <unistd.h>

#include "book_node.h"

#define DB_BASE 1



void open_db(const char* file_name);
void close_db(void);
Node* db_read_book_list(void);
void db_write_book(const Book* book);
int db_check_book_by_id(const int id);
int db_remove_book_by_id(const int id);
