#include "book_db.h"

int main(void) {
    open_db("Book_steelbear.dbx");

    db_write_book(create_book(
        1,
        (char[TITLE_MAX]){"clanguage"},
        (char[AUTHOR_MAX]){"K&R"},
        (char[PUBLISH_MAX]){"19880322"},
        (char[RECOM_MAX]){"The C Programming Language"},
        33000
    ));

    db_write_book(create_book(
        2,
       (char[TITLE_MAX]){"c++language"},
       (char[AUTHOR_MAX]){"Stroustrup"},
       (char[PUBLISH_MAX]){"20151230"},
       (char[RECOM_MAX]){"The C++ Programming Language"},
        0
    ));

    db_write_book(create_book(
        3,
       (char[TITLE_MAX]){"code"},
       (char[AUTHOR_MAX]){"Petzold"},
       (char[PUBLISH_MAX]){"20101011"},
       (char[RECOM_MAX]){"The hidden Language of Computer HardWare and SoftWare"},
        25000
    ));

    db_write_book(create_book(
        4,
       (char[TITLE_MAX]){"pearls"},
       (char[AUTHOR_MAX]){"Bently"},
       (char[PUBLISH_MAX]){"20030215"},
       (char[RECOM_MAX]){"Programming Pearls, 2/E"},
        22000
    ));

    db_write_book(create_book(
        5,
       (char[TITLE_MAX]){"nand2tetris"},
       (char[AUTHOR_MAX]){"Nisan"},
       (char[PUBLISH_MAX]){"20190320"},
       (char[RECOM_MAX]){"Building a Modern Computer from First Principles"},
        26000
    ));

    db_write_book(create_book(
        6,
       (char[TITLE_MAX]){"concrete_mathematics"},
       (char[AUTHOR_MAX]){"Knuth"},
       (char[PUBLISH_MAX]){"20180420"},
       (char[RECOM_MAX]){"Concrete Mathematics"},
        49000
    ));

    db_write_book(create_book(
        7,
       (char[TITLE_MAX]){"sicp"},
       (char[AUTHOR_MAX]){"Abelson"},
       (char[PUBLISH_MAX]){"20071027"},
       (char[RECOM_MAX]){"Structure and Interpretation of Computer Programs"},
        40000
    ));

    db_write_book(create_book(
        8,
       (char[TITLE_MAX]){"fluent_python"},
       (char[AUTHOR_MAX]){"Ramalho"},
       (char[PUBLISH_MAX]){"20160812"},
       (char[RECOM_MAX]){"Fluent Python for Pythonist"},
        0
    ));

    db_write_book(create_book(
        9,
       (char[TITLE_MAX]){"rendering"},
       (char[AUTHOR_MAX]){"Pharr"},
       (char[PUBLISH_MAX]){"20200107"},
       (char[RECOM_MAX]){"Physically based rendering from theory to implementation"},
        89000
    ));

    db_write_book(create_book(
        10,
       (char[TITLE_MAX]){"operating_system"},
       (char[AUTHOR_MAX]){"Silberschatz"},
       (char[PUBLISH_MAX]){"20200228"},
       (char[RECOM_MAX]){"Operating System Concepts"},
        39000
    ));
    
    close_db();

    return 0;
}