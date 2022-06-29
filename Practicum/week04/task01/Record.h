#ifndef RECORD_N
#define RECORD_N

class Record
{
public:
    char* mWord;
    char* mMeaning;

    void init(const char*, const char*);
    Record copy() const;
    void print() const;
    void deleteDynamic();
};

#endif