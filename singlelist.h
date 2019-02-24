#ifndef SINGLELIST_H
#define SINGLELIST_H
#include <assert.h>
#include <stddef.h>
#include <iostream>
#include <list>

using namespace std;

template <typename T>
struct Cell {
    T value;
    Cell* next;
};

template <typename T>
class SingleList
{
private:
    Cell<T>* begin;
    Cell<T>* end;
    int len;
public:
    SingleList();
    void push(T value);
    T pop();
    void insert(unsigned int pos, T value);
    string get_string(string splitter = " ");

    static void test();
};

#endif // SINGLELIST_H
