pool6: main.c book.o book_node.o book_db.o
	gcc -o pool6 main.c book.o book_node.o book_db.o
book.o: book.c book.h
	gcc -c book.c
book_node.o: book_node.c book_node.h
	gcc -c book_node.c
book_db.o: book_db.c book_db.h
	gcc -c book_db.c