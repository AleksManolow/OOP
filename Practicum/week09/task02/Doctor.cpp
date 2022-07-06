#include"Doctor.h"
char* Doctor::allocateMemory(char* s)
{   
    int len = strlen(s);
    char* result = new char[len + 1];
    strcpy(result, s);
    return result;
}

Doctor::Doctor(char* _name, size_t _numberOfPatiens , Patient* _patients , unsigned _idN)
{
    name = allocateMemory(_name);
    numberOfPatients = _numberOfPatiens;
    patients = new Patient[numberOfPatients];
    for (int i = 0; i < numberOfPatients; i++)
    {
        patients[i] = _patients[i];
    }
    idN = _idN;
}

Doctor::~Doctor()
{
    delete[] name;
    delete[] patients;
}

double Doctor::avarageVisit()
{
    double sum = 0;
    for (int i = 0; i < numberOfPatients; i++)
    {
        sum += patients[i].getNumberOfVisits();
    }
    return sum / numberOfPatients;
}
int Doctor::numberOfPatientsWhoMadeMore(int visits)
{
    int cout = 0;
    for (int i = 0; i < numberOfPatients; i++)
    {
        if (patients[i].getNumberOfVisits() > visits )
        {
            cout++;
        }
    }
    return cout;
}
Patient Doctor::operator[](int index)
{
    if(index < 0 || index > numberOfPatients)
    {
        throw "Invalid index\n";
    }
    return patients[index];
}

std::ostream& Doctor::operator<<(std::ostream& out)
{
    out << strlen(name) << ' ' <<name << "\n";
    out << numberOfPatients << "\n";
    for (int i = 0; i < numberOfPatients; i++)
    {
        patients[i].operator<<(out);
    }
    out << idN << "\n";
    
    return out;
}

void Doctor::print()
{
    std::cout << "---------------------" << std::endl;
    std::cout << name << std::endl;
    std::cout << numberOfPatients << std::endl;
    for (int i = 0; i < numberOfPatients; i++)
    {
        patients[i].print();
    }
    std::cout << idN << std::endl;
    std::cout << "---------------------" << std::endl;
    
}

