#include <iostream>
#include "find.h"

using namespace std;

int main()
{
    //Find f;
    int a[6] = {1,2,3,4,5,6};


    cout << Find::full({1,2,3,4,5,6}, 2) << endl;
    cout << Find::barrier({1,2,3,4,5,6}, 3) << endl;
    cout << Find::binary({1,2,3,4,5,6}, 4) << endl;

    cout << Find::full(a, 2, end(a))     << endl;
    return 0;
}
