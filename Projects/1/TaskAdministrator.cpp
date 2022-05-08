#include"TaskAdministrator.h"

TaskAdministrator::TaskAdministrator()
{
    booksFile = "BookList.txt";
    usersFile = "UserList.txt";
    char* temp = booksFile.returnChar();
    std::fstream books(temp, std::ios::in | std::ios::out);
    books >> bookList;
    books.close();
    temp = usersFile.returnChar();
    std::fstream users(temp, std::ios::in | std::ios::out);
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
void TaskAdministrator::sortB()
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
void TaskAdministrator::findB()
{
    String input;
    std::cout << "Select criteria for finding the book \"Title\", \"Author\", \"ISBN\" or \"Description\"." << std::endl;
    std::cout << "Enter: ";
    std::cin >> input;
    if (input == "Title")
    {
        std::cout << "Enter Title: ";
        std::cin >> input;
        bool notFound = true;
        for (int i = 0; i < bookList.getSize(); i++)
        {
            if (bookList[i].getTitle() == input)
            {
                bookList[i].writeToStream(std::cout);
                notFound = false;
            }  
        }
        if (notFound)
        {
            std::cout << "No book found!" << std::endl;
        }
    }
    else if (input == "Author")
    {
        std::cout << "Enter Author: ";
        std::cin >> input;
        bool notFound = true;
        for (int i = 0; i < bookList.getSize(); i++)
        {
            if (bookList[i].getAuthor() == input)
            {
                bookList[i].writeToStream(std::cout);
                notFound = false;
            }  
        }
        if (notFound)
        {
            std::cout << "No book found!" << std::endl;
        }
    }
    else if (input == "ISBN")
    {
        std::cout << "Enter ISBN: ";
        std::cin >> input;
        bool notFound = true;
        for (int i = 0; i < bookList.getSize(); i++)
        {
            if (bookList[i].getISBN() == input)
            {
                bookList[i].writeToStream(std::cout);
                notFound = false;
            }  
        }
        if (notFound)
        {
            std::cout << "No book found!" << std::endl;
        }
    }
    else if (input == "Description")
    {
        std::cout << "Enter Description: ";
        std::cin >> input;
        bool notFound = true;
        for (int i = 0; i < bookList.getSize(); i++)
        {   
            size_t inputLen = input.size();
            String temp = bookList[i].getShortDescripion();
            bool isDescriptionFromBook = false;
            for (int j = 0; j < temp.size(); j++) 
            {
                for (int k = 0, p = j; k < inputLen; p++, k++)
                {
                    if (!(temp[p] == input[k] || temp[p] == (char)(input[k] - 32) || temp[p] == (char)(input[k] + 32)))
                    {
                        break;
                    }
                    if (k == inputLen - 1)
                    {
                        isDescriptionFromBook = true;
                    }  
                }
            }
            if (isDescriptionFromBook)
            {
                bookList[i].writeToStream(std::cout);
                notFound = false;
            }
        }
        if (notFound)
        {
            std::cout << "No book found!" << std::endl;
        }
    }
    else
    {
        std::cerr << "Invalid criteria for finding the book!" << std::endl;
    }
}
bool TaskAdministrator::isRegistered(User& u)
{
    for (int i = 0; i < userList.getSize(); i++)
    {
        if (userList[i] == u)
        {
            return true;
        } 
    }
    return false;
}
void TaskAdministrator::addB()
{   
    User user;
    String choice;
    do
    {
        user.readUser(std::cin);
        if (isRegistered(user))
        {
            Book newBook;
            std::cout << "Enter which book you want to add!" << std::endl;
            newBook.loadFromStream(std::cin);
            bookList.pushBack(newBook);

            char* temp = newBook.getNameFile().returnChar();
            std::fstream textOfBook(temp, std::ios::in | std::ios::out | std::ios::trunc);

            //trqnwa da izmislq kak da procheta texta
            //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            //-------------------------
            //---------------------
            //-------------------------
            //--------------------------

            //add and from the file
            temp = booksFile.returnChar();
            std::fstream books(temp, std::ios::in | std::ios::out | std::ios::trunc);
            books << bookList;
            books.close();
            std::cout << "The book has been added successfully! " << std::endl;
        }
        else
        {
            std::cout << "Login failed! "<< std::endl;
            std::cout << "\"Try again\" or \"Come back\"!" << std::endl;
            std::cout << "Enter: ";
            std::cin >> choice;
        }
    } while (!(isRegistered(user)) && !(choice == "Come back"));

}
void TaskAdministrator::removeB()
{
    User user;
    String choice;
    do
    {
        user.readUser(std::cin);
        if (isRegistered(user))
        {
            std::cout << "Hello, "<<  user.getUsername() << " login successful!" << std::endl;

            Book removalBook;
            std::cout << "Enter which book you want to remove!" << std::endl;
            removalBook.loadFromStream(std::cin);
            bool notFound = true;
            int i = 0;
            for (i ; i < bookList.getSize(); i++)
            {
                if (bookList[i] == removalBook)
                {
                    notFound = false;
                    break;
                }
            }
            if (notFound)
            {
                std::cout << "No such book has been found!"<< std::endl;
            }
            else
            {
                std::cout << "Whether to delete the file related to the book \"Yes\" or \"No\"?"<< std::endl;
                String choice;
                std::cin >> choice;
                char* temp;
                if (choice == "Yes")
                {
                    temp = bookList[i].getNameFile().returnChar();
                    remove(temp);
                }
                bookList.removeAt(i);

                //remove and from the file
                temp = booksFile.returnChar();
                std::fstream books(temp, std::ios::in | std::ios::out | std::ios::trunc);
                books << bookList;
                books.close();
                std::cout << "The book has been removed successfully! " << std::endl;
            } 
        }
        else
        {
            std::cout << "Login failed! "<< std::endl;
            std::cout << "\"Try again\" or \"Come back\"!" << std::endl;
            std::cout << "Enter: ";
            std::cin >> choice;
        }
    } while (!(isRegistered(user)) && !(choice == "Come back"));
}
void TaskAdministrator::outputB()
{
    Book chooseBook;
    std::cout << "Enter a book on which to display the text!" << std::endl;
    chooseBook.loadFromStream(std::cin);
    // -------------
    // ---------------
    // --------------
    // ----------------

}
void TaskAdministrator::TempPrint()
{
    std::cout << bookList;
    std::cout << "-------" << std::endl;
    std::cout << userList;
}