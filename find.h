#ifndef FIND_H
#define FIND_H

#include <math.h>
#define PHI ((1+sqrt(5))/2) // золотое сечение
#include <iostream>

using namespace std;

class Find
{


public:
    Find();
    static int full(int arr[],  int x, int len);
    static int barrier( int arr[],  int x, int len);
    static int binary(  int arr[],  int x, int len);
    static int golden(  int arr[],  int x, int len);

    static int full(    const std::initializer_list<int> values, int x);
    static int barrier( const std::initializer_list<int> values, int x);
    static int binary(  const std::initializer_list<int> values, int x);
    static int golden(  const std::initializer_list<int> values, int x);

};

#endif // FIND_H
