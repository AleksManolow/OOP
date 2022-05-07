#ifndef USER_H
#define USER_H

#include"String.h"
#include <conio.h>

class User
{
private:
    String username;
    String password;
public:
    User();

    bool operator==(const User& other) const;

    void readUser(std::istream& is);

    friend std::istream& operator>>(std::istream& is, User&);
    friend std::ostream& operator<<(std::ostream& os, const User&);
};

#endif
