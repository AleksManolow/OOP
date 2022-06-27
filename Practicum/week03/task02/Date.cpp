#include"Date.h"

Date Date::readDate(std::ifstream& in)
{
    Date date1;
    in >> date1.mDay;

    int sizeMonth;
    in >> sizeMonth;
    date1.mMonth = new char [sizeMonth + 1];
    in.get();
    in.getline(date1.mMonth, sizeMonth);

    in >> date1.mYear;
    in.get();
    in.get();

    in >> date1.mTime.mHours;
    in.get();
    in >> date1.mTime.mMinutes;
    return date1;
}
void Date::writeDate(std::ofstream& out)
{
    out << mDay << " ";

    out << strlen(mMonth) << " " << mMonth << " ";

    out << mYear << ", ";

    out << mTime.mHours << ":" << mTime.mMinutes<< std::endl;
}