#include "findname.h"

FindName::FindName()
{

}

string FindName::full(Entrant arr[], int x, int len, string splitter)
{
    string result;
    int i;

    i = 0;
    result = arr[0].name;


    while((i < len) && (arr[i].points != x)) {
        i++;
        result = arr[i].name;
    }


    if(i == len) {
        result = "none";
    }else{
        // Если людей с одними и теми же баллами несколько, необходимо вывести из всех.
        for(int j = i + 1; (j < len)&&(arr[j].points == arr[i].points) ; j++) {
            result+= splitter + arr[j].name;
        }
    }

    return result;
}

string FindName::barrier(Entrant arr[], int x, int len, string splitter)
{
    Entrant temp[len+1];
    string result;
    int i;

    copy(arr, arr + len, temp);
    temp[len].points = x;
    result = arr[0].name;

    i = 0;
    while(temp[i].points != x) {
        i++;
        result = arr[i].name;
    }


    if(i == len){
        result = "none";
    } else {
        // Если людей с одними и теми же баллами несколько, необходимо вывести из всех.
        for(int j = i + 1; (j < len)&&(arr[j].points == arr[i].points) ; j++) {
            result+= splitter + arr[j].name;
        }
    }


    return result;
}

string FindName::binary(Entrant arr[], int x, int len, string splitter)
{
    int left;
    int right;
    int mid;
    string result;

    left   = 0;
    right  = len;
    result = "none";


    do {
        mid = (left + right) / 2;

        if(x == arr[mid].points) {
            result = arr[mid].name;
        }

        if(x < arr[mid].points) {
            right = mid - 1;
        } else {
            left  = mid + 1;
        }
    }while((left <= right)&&(result == "none"));


    // Если людей с одними и теми же баллами несколько, необходимо вывести из всех.
    // Из-за особенностей бинарного поиска, циклы фор запускаются в обе стороны.
    for(int j = mid + 1; (j < len) && (arr[j].points == arr[mid].points) && (result != "none"); j++)
    {
        result+= splitter + arr[j].name;
    }
    for(int j = mid - 1; (j > 0)   && (arr[j].points == arr[mid].points) && (result != "none"); j--)
    {
        result = arr[j].name + splitter + result;
    }


    return result;
}

string FindName::golden(Entrant arr[], int x, int len, string splitter)
{
    int left;
    int right;
    int mid;
    string result;

    left   = 0;
    right  = len - 1;
    result = "none";

    do {
        mid = ceil(right - (right - left)/PHI);
        if(x == arr[mid].points) {
            result = arr[mid].name;
        }

        if(x < arr[mid].points) {
            right = mid - 1;
        } else {
            left  = mid + 1;
        }
    }while((left <= right)&&(result == "none"));


    // Если людей с одними и теми же баллами несколько, необходимо вывести из всех.
    // Из-за особенностей бинарного поиска, циклы фор запускаются в обе стороны.
    for(int j = mid + 1; (j < len) && (arr[j].points == arr[mid].points) && (result != "none"); j++)
    {
        result+= splitter + arr[j].name;
    }
    for(int j = mid - 1; (j > 0)   && (arr[j].points == arr[mid].points) && (result != "none"); j--)
    {
        result = arr[j].name + splitter + result;
    }


    return result;
}
