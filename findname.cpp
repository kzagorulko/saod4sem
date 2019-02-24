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

void FindName::test()
{
    // Задаём массив
    FindName::Entrant rating[12] = {
        {98, "Ivan Petrov"},
        {97, "Vasilij Sidorov"},
        {76, "Andey Panov"},
        {90, "Kirill Emeljanov"},
        {73, "Avror Vorontsov"},
        {99, "Michael Afanas'ev"},
        {81, "Arsen Socolov"},
        {73, "Igor Isakov"},
        {92, "Stepan Vishnyakov"},
        {70, "Arsenij Tyrov"},
        {85, "Leonid Volokitin"},
        {96, "Afanasij Efimov"}

    };

    sort(rating, end(rating));

    cout << "Entrants with points:" << endl;
    for(auto it = rating; it != end(rating); it++) {
        cout << it->points << "\t" << it->name << endl;
    }

    cout << "Tests values:" << endl;
    int targetValue[5] = {98, 70, 99, 73, 101};
    for(int i = 0; i < (end(targetValue) - targetValue); i++) {
        cout << "Target value - " << targetValue[i] << ":" << endl;
        cout << " Full:    " << FindName::full(    rating, targetValue[i], 12) << endl;
        cout << " Barrier: " << FindName::barrier( rating, targetValue[i], 12) << endl;
        cout << " Binary:  " << FindName::binary(  rating, targetValue[i], 12) << endl;
        cout << " Gold:    " << FindName::golden(  rating, targetValue[i], 12) << endl;
        cout << endl;
    }


    int tPoint;
    cout << "Enter points or press Ctrl+D(Ctrl+Z) to exit: ";
    while(cin >> tPoint) {
        int count;
        string res;
        string splitter;
        res = FindName::golden(rating, tPoint, 12);
        istringstream ist (res);

        // счётчик слов
        count = 0;
        while(ist >> res) {
            count++;
        }

        // Если количество слов больше двух, предлагается выбрать разделитель между именами
        if(count > 2) {
            cout << "found a few Entrants. Change a splitter (for exmpl. \";\", \" \"): ";
            cin.get();
            getline(cin, splitter);

            // Символы табуляции и переноса строки должны корректно отображаться.
            for(unsigned int i = 0; i < splitter.length() - 1; i++) {
                if (splitter[i] == '\\'){
                    switch(splitter[i+1]) {
                        case 'n' : { splitter[i] = ' '; splitter[i+1] = '\n'; break; }
                        case 't' : { splitter[i] = ' '; splitter[i+1] = '\t'; break; }
                    }
                }
            }
        }

        cout << FindName::golden(rating, tPoint, 12, splitter) << endl;
        cout << "Enter points or press Ctrl+D(Ctrl+Z) to exit: ";
    }
}
