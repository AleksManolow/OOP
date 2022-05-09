#ifndef TASKADMINISTRATOR_H
#define TASKADMINISTRATOR_H
#include"String.h"
#include"Book.h"
#include"Vector.h"
#include"User.h"
#include<fstream>
#include<stdio.h>
#include <thread>
#include <chrono>
using namespace std::chrono_literals;

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

    //function to check if the username and password are correct
    bool isRegistered(User&);

public:
    TaskAdministrator();

    void sortB();
    void findB();
    void addB();
    void removeB();
    void outputB();
    void helpB();

};

#endif
