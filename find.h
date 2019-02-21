#ifndef FIND_H
#define FIND_H

#include <iostream>

using namespace std;

class Find
{
private:
    int index;
    //int binary(int arr[], int x, int len, bool run = false);
public:
    Find();
    static int full(int arr[], int x, int* arrayEnd);
    static int barrier(int arr[], int x, int len);
    static int binary(int arr[], int x, int len);

    static int full(const std::initializer_list<int> values, int x);
    static int barrier(const std::initializer_list<int> values, int x);
    static int binary(const std::initializer_list<int> values, int x);

};

#endif // FIND_H
