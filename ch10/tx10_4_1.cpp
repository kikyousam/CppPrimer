#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>

using namespace std;

int main(){
    list<int> lst={1,2,3,4};
    list<int> lst2,lst3;
    auto it=inserter(lst,++lst.begin());
    it=5;
    ++it;  //不会改变这个值
    it=6;
    char c=' ';
    ostream &os=cout;
    for_each(lst.cbegin(),lst.cend(),[&os,c](int t){os<<t<<c;});
}