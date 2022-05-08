#ifndef TASKADMINISTRATOR_H
#define TASKADMINISTRATOR_H
#include"String.h"
#include"Book.h"
#include"Vector.h"
#include"User.h"
#include<fstream>

class TaskAdministrator
{
private:
    Vector<Book> bookList;
    String booksFile;
    Vector<User> userList;
    String usersFile;

    //necessary functions for the sort operation
    void sortListOfBookByTitleAscendingOrder();
    void sortListOfBookByTitleDescendingOrder();
    void sortListOfBookByAuthorAscendingOrder();
    void sortListOfBookByAuthorDescendingOrder();
    void sortListOfBookByRatingAscendingOrder();
    void sortListOfBookByRatingDescendingOrder();
    void printSortListOfBook();

public:
    TaskAdministrator();

    void sort();
    void find();



    void TempPrint();

};







#endif
