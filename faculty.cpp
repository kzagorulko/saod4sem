#include "faculty.h"

list<pair<string, SingleList<string>>>::iterator Faculty::find(string group)
{
    for(list<pair<string, SingleList<string>>>::iterator it  = data.begin();
        it != data.end(); it++) {
        if(it->first == group) {
            return it;
        }
    }
    return data.end();
}

Faculty::Faculty()
{

}

void Faculty::push_back(string group, string name)
{
    list<pair<string, SingleList<string>>>::iterator pos;

    pos = this->find(group);
    if(pos != data.end()) {
        pos->second.push(name);
    } else {
        SingleList<string> * list = new SingleList<string>;
        list->push(name);
        data.push_back(make_pair(group, *list));
    }

}

string Faculty::get_string(string splitter)
{
    string result;
    result = "";

    for(list<pair<string, SingleList<string>>>::iterator it = data.begin(); it != data.end(); it++){
        result+=it->first + splitter + it->second.get_string(splitter) + "\n";

    }

    return result;
}

void Faculty::sort()
{
    data.sort([](const pair<string, SingleList<string>> &a,
              const pair<string, SingleList<string>> &b) {
        return a.first < b.first;
    });

    for(auto i = data.begin(); i != data.end(); ++i) {
        i->second.sort();
    }
}

void Faculty::test()
{
    Faculty it;
    it.push_back("ikbo-01-17", "Zagorulko Konstanin");
    it.push_back("ikbo-03-17", "Vasilij Sidorov");
    it.push_back("ikbo-02-17", "Ivan Petrov");
    it.push_back("ikbo-01-17", "Andey Panov");
    it.push_back("ikbo-01-17", "Kirill Emeljanov");
    it.push_back("ivbo-01-17", "Avror Vorontsov");
    it.push_back("ivbo-02-17", "Michael Afanas'ev");
    it.push_back("ivbo-02-17", "Arsen Socolov");
    it.push_back("ivbo-01-17", "Igor Isakov");
    it.push_back("ikbo-01-17", "Stepan Vishnyakov");
    it.push_back("ikbo-01-17", "Arsenij Tyrov");
    it.push_back("ikbo-03-17", "Leonid Volokitin");
    it.push_back("ikbo-01-17", "Afanasij Efimov");

    cout << it.get_string("\n  ") << endl;

    it.sort();

    cout << it.get_string("\n  ") << endl;

}
