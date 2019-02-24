#ifndef FACULTY_H
#define FACULTY_H
#include <list>
#include <string>
#include <stddef.h>
#include "singlelist.h"

class Faculty
{
private:
    list<pair<string, SingleList<string>>> data;
    list<pair<string, SingleList<string>>>::iterator find(string group);
public:
    Faculty();
    void push_back(string group, string name);
    string pop_back(string group);
    string get_string(string splitter = " ");
    bool insert_afeter(string after, string name);

    static void test();
};

#endif // FACULTY_H
