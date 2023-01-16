#include <string>
#include <iostream>

using namespace std;

void error_msg(initializer_list<string> il){
    for(auto beg=il.begin();beg!=il.end();++beg){
        cout<<*beg<<" ";
    }
    cout<<endl;
}

int main(){
    string actual,expected;
    if(expected!=actual){
        error_msg({"functionalX",expected,actual});
    }
    else    
        error_msg({"functionalX","okay"});
}