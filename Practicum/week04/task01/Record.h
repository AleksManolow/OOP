#ifndef RECORD_N
#define RECORD_N

struct Record
{
    char* mWord;
    char* mMeaning;

    void init(const char*, const char*);
    Record copy() const;
    void print() const;
    void deleteDynamic();
};

#endif