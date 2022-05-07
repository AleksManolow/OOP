#include"TaskAdministrator.h"

TaskAdministrator::TaskAdministrator()
{
    booksFile = "BookList.txt";
    usersFile = "UserList.txt";
    char* temp = booksFile.returnChar();
    std::ifstream books(temp, std::ios::in | std::ios::out);
    books >> bookList;
    books.close();
    temp = usersFile.returnChar();
    std::ifstream users(temp, std::ios::in | std::ios::out);
    users >> userList;
    users.close();
}
void TaskAdministrator::sortListOfBookByTitleAscendingOrder()
{
    for (int i = 0; i < bookList.getSize(); i++)
    {
        for (int j = i + 1; j < bookList.getSize(); j++)
        {
            if (bookList[i].getTitle() > bookList[j].getTitle())
            {
                Book temp = bookList[i];
                bookList[i] = bookList[j];
                bookList[j] = temp;
            } 
        }
    }
}
void TaskAdministrator::sortListOfBookByTitleDescendingOrder()
{
    for (int i = 0; i < bookList.getSize(); i++)
    {
        for (int j = i + 1; j < bookList.getSize(); j++)
        {
            if (bookList[i].getTitle() < bookList[j].getTitle())
            {
                Book temp = bookList[i];
                bookList[i] = bookList[j];
                bookList[j] = temp;
            } 
        }
    }
}
void TaskAdministrator::sortListOfBookByAuthorAscendingOrder()
{
    for (int i = 0; i < bookList.getSize(); i++)
    {
        for (int j = i + 1; j < bookList.getSize(); j++)
        {
            if (bookList[i].getAuthor() > bookList[j].getAuthor())
            {
                Book temp = bookList[i];
                bookList[i] = bookList[j];
                bookList[j] = temp;
            } 
        }
    }
}
void TaskAdministrator::sortListOfBookByAuthorDescendingOrder()
{
    for (int i = 0; i < bookList.getSize(); i++)
    {
        for (int j = i + 1; j < bookList.getSize(); j++)
        {
            if (bookList[i].getAuthor() < bookList[j].getAuthor())
            {
                Book temp = bookList[i];
                bookList[i] = bookList[j];
                bookList[j] = temp;
            } 
        }
    }
}
void TaskAdministrator::sortListOfBookByRatingAscendingOrder()
{
    for (int i = 0; i < bookList.getSize(); i++)
    {
        for (int j = i + 1; j < bookList.getSize(); j++)
        {
            if (bookList[i].getRating() > bookList[j].getRating())
            {
                Book temp = bookList[i];
                bookList[i] = bookList[j];
                bookList[j] = temp;
            } 
        }
    }
}
void TaskAdministrator::sortListOfBookByRatingDescendingOrder()
{
    for (int i = 0; i < bookList.getSize(); i++)
    {
        for (int j = i + 1; j < bookList.getSize(); j++)
        {
            if (bookList[i].getRating() < bookList[j].getRating())
            {
                Book temp = bookList[i];
                bookList[i] = bookList[j];
                bookList[j] = temp;
            } 
        }
    }
}
void TaskAdministrator::printSortListOfBook()
{
    std::cout <<"--------------------" << std::endl; 
    std::cout << "Title, Author, ISBN" << std::endl;
    for (int  i = 0; i < bookList.getSize(); i++)
    {
        std::cout << bookList[i].getTitle() << ", " << bookList[i].getAuthor() << ", " << bookList[i].getISBN() << std::endl;
    }
    std::cout <<"--------------------" << std::endl;
}
void TaskAdministrator::sort()
{
    String sortOrder;
    std::cout << "Select sort order \"Ascending\" or \"Descending\"." << std::endl;
    std::cout << "Enter: ";
    std::cin >> sortOrder;
    if (sortOrder == "Ascending")
    {
        String sortField;
        std::cout << "Select sort field \"Title\", \"Author\" or \"Rating\"." << std::endl;
        std::cout << "Enter: ";
        std::cin >>  sortField;
        if (sortField == "Title")
        {
            sortListOfBookByTitleAscendingOrder();
        }
        else if (sortField == "Author")
        {
            sortListOfBookByAuthorAscendingOrder();
        }
        else if(sortField == "Rating")
        {
            sortListOfBookByRatingAscendingOrder();
        }
        else
        {
            std::cerr << "Invalid field for sort!" << std::endl;
        }
    }
    else if (sortOrder == "Descending")
    {
        String sortField;
        std::cout << "Select sort field \"Title\", \"Author\" or \"Rating\"." << std::endl;
        std::cout << "Enter: ";
        std::cin >>  sortField;
        if (sortField == "Title")
        {
            sortListOfBookByTitleDescendingOrder();
        }
        else if (sortField == "Author")
        {
            sortListOfBookByAuthorDescendingOrder();
        }
        else if(sortField == "Rating")
        {
            sortListOfBookByRatingDescendingOrder();
        }
        else
        {
            std::cerr << "Invalid field for sort!" << std::endl;
        }
    }
    else
    {
        std::cerr << "Invalid sord order!" << std::endl;
    }
    printSortListOfBook();
}
void TaskAdministrator::TempPrint()
{
    std::cout << bookList;
    std::cout << "-------" << std::endl;
    std::cout << userList;
}