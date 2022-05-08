#include"User.h"

User::User()
{
    username = "";
    password = "";
}

bool User::operator==(const User& other) const
{
    if (username == other.username && password == other.password)
    {
        return true;
    }
    return false;
}
void User::readUser(std::istream& is)
{
    std::cout << "Username: ";
    is >> username;
    std::cout << "Password: ";
    
    char pass[32];//to store password.
    int i = 0;
    char a;//a Temp char
    while(true)//infinite loop
    {
        a=getch(); //stores char typed in a
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9')) //check if a is numeric or alphabet
        {
            pass[i]=a;//stores a in pass
            ++i;
            std::cout<<"*";
        }
        if(a=='\b'&&i>=1)//if user typed backspace
            //i should be greater than 1.
        {
            std::cout<<"\b \b";//rub the character behind the cursor.
            --i;
        }
        if(a=='\r')//if enter is pressed
        {
            pass[i]='\0';//null means end of string.
            break;//break the loop
        }
    }
    std::cout << std::endl;
    password = pass;
}
String User::getUsername()
{
    return username;
}
std::istream& operator>>(std::istream& is, User& user)
{
    is >> user.username;
    is >> user.password;

    return is;
}
std::ostream& operator<<(std::ostream& os, const User& user)
{
    os << user.username << '\n';
    os << user.password << '\n';

    return os;
}