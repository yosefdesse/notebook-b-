#define CHECK DOCTEST_CHECK
#include "doctest.h"
using namespace doctest;
#include <iostream>

#include "Notebook.hpp"
#include "Direction.hpp"
using ariel::Direction;
using namespace ariel ;





TEST_CASE("Good notebook") {
    Notebook notebook ;
    notebook.write(/*page=*/100 ,/*row=*/100, /*column=*/200, Direction::Horizontal, "yosefdese") ;
    CHECK( notebook.read(/*page=*/100 ,/*row=*/100, /*column=*/200, Direction::Horizontal, /*length=*/2)== "yo" );
    CHECK( notebook.read(/*page=*/100 ,/*row=*/100, /*column=*/201, Direction::Horizontal, /*length=*/1)== "y" );
    CHECK( notebook.read(/*page=*/100 ,/*row=*/100, /*column=*/200, Direction::Horizontal, /*length=*/5)== "yosef" );
    CHECK( notebook.read(/*page=*/100 ,/*row=*/100, /*column=*/200, Direction::Horizontal, /*length=*/3)== "yos" );
    CHECK( notebook.read(/*page=*/100 ,/*row=*/100, /*column=*/200, Direction::Horizontal, /*length=*/9)== "yosefdese" );

    notebook.write(/*page=*/100 ,/*row=*/60, /*column=*/100, Direction::Vertical, "hello") ;
    CHECK( notebook.read(/*page=*/100 ,/*row=*/60, /*column=*/100, Direction::Vertical, /*length=*/1)== "h" );
    CHECK( notebook.read(/*page=*/100 ,/*row=*/60, /*column=*/100, Direction::Vertical, /*length=*/1)== "he" );
    CHECK( notebook.read(/*page=*/100 ,/*row=*/60, /*column=*/100, Direction::Vertical, /*length=*/5)== "hello" );
    CHECK( notebook.read(/*page=*/100 ,/*row=*/60, /*column=*/100, Direction::Vertical, /*length=*/6)== "hello_" );
    CHECK( notebook.read(/*page=*/100 ,/*row=*/60, /*column=*/98, Direction::Vertical, /*length=*/9)== "__hello__" );

    notebook.write(/*page=*/100 ,/*row=*/230, /*column=*/120, Direction::Horizontal, "abcdefgh") ;
    CHECK( notebook.read(/*page=*/100 ,/*row=*/230, /*column=*/120, Direction::Horizontal, /*length=*/1)== "a" );
    CHECK( notebook.read(/*page=*/100 ,/*row=*/230, /*column=*/120, Direction::Horizontal, /*length=*/2)== "ab" );
    CHECK( notebook.read(/*page=*/100 ,/*row=*/230, /*column=*/120, Direction::Horizontal, /*length=*/3)== "abc" );
    CHECK( notebook.read(/*page=*/100 ,/*row=*/230, /*column=*/120, Direction::Horizontal, /*length=*/4)== "abcd" );
    CHECK( notebook.read(/*page=*/100 ,/*row=*/230, /*column=*/120, Direction::Horizontal, /*length=*/5)== "abcde" );
    CHECK( notebook.read(/*page=*/100 ,/*row=*/230, /*column=*/120, Direction::Horizontal, /*length=*/6)== "abcdef" );
    CHECK( notebook.read(/*page=*/100 ,/*row=*/230, /*column=*/120, Direction::Horizontal, /*length=*/7)== "abcdefg" );
    CHECK( notebook.read(/*page=*/100 ,/*row=*/230, /*column=*/120, Direction::Horizontal, /*length=*/8)== "abcdefgh" );


    notebook.write(/*page=*/100 ,/*row=*/500, /*column=*/300, Direction::Horizontal, "newnotebook") ;
    CHECK( notebook.read(/*page=*/100 ,/*row=*/500, /*column=*/300, Direction::Horizontal, /*length=*/2)== "ne" );
    CHECK( notebook.read(/*page=*/100 ,/*row=*/500, /*column=*/300, Direction::Horizontal, /*length=*/1)== "n" );
    CHECK( notebook.read(/*page=*/100 ,/*row=*/500, /*column=*/300, Direction::Horizontal, /*length=*/5)== "newbo" );
    CHECK( notebook.read(/*page=*/100 ,/*row=*/500, /*column=*/300, Direction::Horizontal, /*length=*/3)== "new" );
    CHECK( notebook.read(/*page=*/100 ,/*row=*/500, /*column=*/300, Direction::Horizontal, /*length=*/9)== "newnotebook_" );




}