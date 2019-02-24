#include "singlelist.h"

template <typename T>
SingleList<T>::SingleList()
{
    len = 0;
}

template <typename T>
T SingleList<T>::pop()
{
    assert(len > 0);

    Cell<T>* temp = begin;
    Cell<T>* temp2;
    while(temp->next != NULL) {
        temp2 = temp;
        temp = temp->next;
    }

    temp2->next = NULL;
    end = temp2;
    len--;

    return temp->value;
}

template<typename T>
void SingleList<T>::insert(unsigned int pos, T value)
{
    Cell<T> *temp;
    Cell<T> *newCell;
    assert((unsigned)this->len >= pos);

    if((unsigned)this->len == pos) {
        push(value);
    } else {

        newCell = new Cell<T>;
        newCell->value = value;

        if(pos == 0) {
            newCell->next = begin;
            begin = newCell;
        } else {

            temp = begin;
            for(unsigned int i = 0; i < pos-1; i++) {
                temp = temp->next;
            }
            newCell->next = temp->next;
            temp->next    = newCell;

        }
        this->len++;
    }
}


template <typename T>
void SingleList<T>::push(T value)
{

    Cell<T>* temp = new Cell<T>;
    temp->next  = NULL;
    temp->value = value;

    if(len == 0) {
        begin = temp;
        end   = temp;
    }
    end->next = temp;
    end = temp;
    len++;
}

template <typename T>
string SingleList<T>::get_string(string splitter)
{
    string result;
    Cell<T>* temp = begin;
    result = "";

    while(temp != end) {
        result+= temp->value;
        result+= splitter;
        temp = temp->next;
    }
    result+=temp->value;

    return result;
}

template<typename T>
void SingleList<T>::test()
{
    SingleList<string> students;
    students.push("Ivan Petrov");
    students.push("Vasilij Sidorov");
    students.push("Andey Panov");
    students.push("Kirill Emeljanov");
    students.push("Avror Vorontsov");
    students.push("Michael Afanas'ev");
    students.push("Arsen Socolov");
    students.push("Igor Isakov");
    students.push("Stepan Vishnyakov");
    students.push("Arsenij Tyrov");
    students.push("Leonid Volokitin");
    students.push("Afanasij Efimov");
    cout << students.get_string("\n");

    list<SingleList<string>> groups;
    groups.push_back(students);

}

template class SingleList<int>;
template class SingleList<string>;
