#ifndef INC
#define INC
#include "vector_.hpp"
#include "list.hpp"
#include "Treenode.hpp"
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;
//#include <boost/format.hpp>

// https://stackoverflow.com/questions/10033373/c-error-nullptr-was-not-declared-in-this-scope-in-eclipse-ide
//  解決null無法編譯的問題 g++ -std=c++0x *.cpp -o output
/*
inset pair
make_pair(val, min(val, v.getMin()))

//#string 轉成char
/*https://www.delftstack.com/zh-tw/howto/cpp/how-to-convert-string-to-char-array-in-cpp/
    auto ptr = str.cstr();//ptr is char*
*/

template <typename T>
T MAX(T &a, T &b)
{
    return (a > b) ? a : b;
}
template <typename T>
string __to_string(T a)
{
    return to_string(a);
}
//#####Tree

#endif