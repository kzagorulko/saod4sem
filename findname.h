#ifndef FINDNAME_H
#define FINDNAME_H
#include <string>
#include <iostream>
#include <math.h>

#define PHI ((1+sqrt(5))/2)
using namespace std;


class FindName
{

public:
    struct Entrant
    {
        int points;
        string name;
        bool operator <(const Entrant &elm)
        {
           return points < elm.points;
        }
    };
    FindName();
    Entrant a;

    static string full(Entrant arr[],  int x, int len, string splitter = " ");
    static string barrier( Entrant arr[],  int x, int len, string splitter = " ");
    static string binary(Entrant arr[],  int x, int len, string splitter = " ");
    static string golden(  Entrant arr[],  int x, int len, string splitter = " ");
};

#endif // FINDNAME_H
