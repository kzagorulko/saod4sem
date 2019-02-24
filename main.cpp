#include <iostream>
#include <algorithm>
#include <sstream>
#include "find.h"
#include "findname.h"

using namespace std;

int main()
{



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


    return 0;
}
