#include "find.h"
#include "algorithm"

Find::Find()
{
    int a[10] = {1,2,3,8,5,6,7,8,9,10};

    int len = 0;
    for(auto it = begin(a); it != end(a); it++) {
        cout << *it << endl;
        len++;
    }
    this->index = len/2;
    cout << "Result: "  << Find::full(a, 8, end(a)) << endl;
    cout << "Result2: " << Find::barrier(a, 8, len) << endl;
    sort(a, end(a));
    cout << "Result3: " << Find::binary(a, 8, len)  << endl;
}

int Find::full(int arr[], int x, int *arrayEnd)
{
    auto it = arr;
    int result;
    result = 0;
    while((it != arrayEnd) && (*it != x)) {
        it++;
        result++;
    }
    if(it == arrayEnd) {
        *it = -1;
    }

    return result;
}

int Find::barrier(int arr[], int x, int len)
{
    int * temp = new int[len+1];
    copy(arr, arr + len * sizeof(int), temp);
    temp[len] = x;
    int it = 0;
    while(temp[it] != x) {
        it++;
    }

    delete temp;

    return (it == len ? -1 : it);
}

int Find::binary(int arr[], int x, int len)
{
    int left;
    int right;
    int result;

    left   = 0;
    right  = len;
    result = -1;

    do {
        int mid;
        mid = (left + right) / 2;

        if(x == arr[mid]) {
            result = mid;
        }

        if(x < arr[mid]) {
            right = mid - 1;
        } else {
            left  = mid + 1;
        }
    }while((left <= right)&&(result == -1));



    return result;
}

int Find::full(const std::initializer_list<int> values, int x)
{
    int len = 0;
    for(auto it = values.begin(); it != values.end(); ++it) {
        len++;
    }
    int arr[len];
    int i = 0;
    for(auto it = values.begin(); it != values.end(); ++it) {
        arr[i++] = *it;
    }
    return full(arr, x, arr + len * sizeof(int));
}

int Find::barrier(const std::initializer_list<int> values, int x)
{
    int len = 0;
    for(auto it = values.begin(); it != values.end(); ++it) {
        len++;
    }
    int arr[len];
    int i = 0;
    for(auto it = values.begin(); it != values.end(); ++it) {
        arr[i++] = *it;
    }
    return barrier(arr, x, len);
}

int Find::binary(const std::initializer_list<int> values, int x)
{
    int len = 0;
    for(auto it = values.begin(); it != values.end(); ++it) {
        len++;
    }
    int arr[len];
    int i = 0;
    for(auto it = values.begin(); it != values.end(); ++it) {
        arr[i++] = *it;
    }
    return binary(arr, x, len);
}



