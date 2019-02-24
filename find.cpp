#include "find.h"
#include "algorithm"

Find::Find()
{

}

int Find::full(int arr[], int x, int len)
{
    int result;
    int i;
    i = 0;
    result = arr[0];
    while((i < len) && (arr[i] != x)) {  // 2 сравнения
        i++;
        result++;
    }
    if(i == len) {                       // сравнение
        result = -1;
    }

    return result;                       // Итог: 2n + 1 сравнений
}

int Find::barrier(int arr[], int x, int len)
{
    int * temp = new int[len+1];
    copy(arr, arr + len, temp);
    temp[len] = x;
    int it = 0;
    while(temp[it] != x) {          // Сравение
        it++;
    }

    delete temp;

    return (it == len ? -1 : it);   // Сравнение. Итог n + 1 сравенией
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
    }while((left <= right)&&(result == -1));    // с каждей итерациией облать уменьшается в 2 раза
                                                // значит сложность лагоритма -- log2(n)

    return result;
}

/* Золотое сечение
 *
 */
int Find::golden(int arr[], int x, int len)
{
    int left;
    int right;
    int result;

    left   = 0;
    right  = len - 1;
    result = -1;

    do {
        int mid;

        mid = ceil(right - (right - left)/PHI);
        if(x == arr[mid]) {
            result = mid;
        }

        if(x < arr[mid]) {
            right = mid - 1;
        } else {
            left  = mid + 1;
        }
    }while((left <= right)&&(result == -1));    // с каждей итерациией облать уменьшается в 2 раза
                                                // значит сложность лагоритма -- log2(n)

    return result;
}

int Find::full(const std::initializer_list<int> values, int x)
{
    int len = 0;
    len = values.end() - values.begin();
    int arr[len];
    int i = 0;
    for(auto it = values.begin(); it != values.end(); ++it) {
        arr[i++] = *it;
    }
    return full(arr, x, len);
}

int Find::barrier(const std::initializer_list<int> values, int x)
{
    int len = 0;
    len = values.end() - values.begin();
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
    len = values.end() - values.begin();
    int arr[len];
    int i = 0;
    for(auto it = values.begin(); it != values.end(); ++it) {
        arr[i++] = *it;
    }
    return binary(arr, x, len);
}

int Find::golden(const std::initializer_list<int> values, int x)
{
    int len = 0;
    len = values.end() - values.begin();
    int arr[len];
    int i = 0;
    for(auto it = values.begin(); it != values.end(); ++it) {
        arr[i++] = *it;
    }
    return golden(arr, x, len);
}

void Find::test()
{
    int a[6] = {1,2,3,4,5,6};

    int len = 0;
    for(auto it = begin(a); it != end(a); it++) {
        cout << *it << endl;
        len++;
    }

    cout << Find::full({1,2,3,4,5,6}, 1)    << endl;
    cout << Find::barrier({1,2,3,4,5,6}, 2) << endl;
    cout << Find::binary({1,2,3,4,5,6}, 3)  << endl;
    cout << Find::golden({1,2,3,4,5,6,7,8,9,10}, 4)  << endl;
    cout << "Golden ratio: " << Find::golden(a, 5, 6) << endl;
    cout << Find::full(a, 15, end(a) - begin(a))     << endl;
}



