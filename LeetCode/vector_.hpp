#ifndef VECTOR_
#define VECTOR_
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <typeinfo>
#include <stdexcept>
using namespace std;
template <typename T>
vector<T> arr_to_vector(T a[], int len)
{ /*
    int a[] = {0, 1, 2, 3, 7, 8, 9, 15};
    vector<int> v = arr_to_vector(a, (sizeof(a) / sizeof(int)));
    */
    if (typeid(T) == typeid(int) || typeid(T) == typeid(float) || typeid(T) == typeid(double) ||
        typeid(T) == typeid(char) || typeid(T) == typeid(long int) || typeid(T) == typeid(unsigned int) || typeid(T) == typeid(unsigned long int))
    {

        vector<T> v;
        v.assign(a, a + len);
        return v;
    }
    else
    {
        throw invalid_argument("The type of the input is not general type ex int ,float ,double ,char.,.etc");
    }
}

template <typename T>
void vector_print(vector<T> &v, bool annotation = true)
{ // typename std::vector<T>::iterator it; https://stackoverflow.com/questions/3144604/stdvectortiterator-it-doesnt-compile/3144609
    typename vector<T>::iterator it = v.begin();
    if (annotation == true)
    {
        for (; it != v.end(); it++)
            cout << " " << *it << endl;
    }
    else
    {
        for (; it != v.end(); it++)
            cout << *it << endl;
    }
}
template <typename T>
void vector_print_no_newline(vector<T> &v, bool annotation = true)
{ // typename std::vector<T>::iterator it; https://stackoverflow.com/questions/3144604/stdvectortiterator-it-doesnt-compile/3144609
    typename vector<T>::iterator it = v.begin();
    if (annotation == true)
    {
        for (; it != v.end(); it++)
            cout << " " << *it;
    }
    else
    {
        for (; it != v.end(); it++)
            cout << *it;
    }
    cout << endl;
}
template <typename T>
void vector_print2D(vector<vector<T>> &v)
{
    vector<vector<int>>::iterator row;
    vector<int>::iterator col;
    for (row = v.begin(); row != v.end(); row++)
    {
        for (col = row->begin(); col != row->end(); col++)
        {
            cout << *col << " ";
        }
        cout << endl;
    }
}
#endif