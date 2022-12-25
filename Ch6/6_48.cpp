#include <string>
#include <cassert>
#include <iostream>

using std::string;
using std::cin;


int main(){
    string s;
    while(cin>>s&&s!="sought") {}
    assert(!cin||s=="sought");
}