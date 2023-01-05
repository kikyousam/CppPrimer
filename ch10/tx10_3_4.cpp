#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool check_size(const string& s, string::size_type sz){
    return s.size()>sz;
}

int main(){
    auto check6=bind(check_size,_1,6);
    string s = "hello world";
    bool b1=check6(s);
    cout<<b1<<endl;
    string::size_type sz=6;
    vector<string> words;
    auto wc=find_if(words.begin(),words.end(),[sz](const string s){
        return s.size()>sz;
    });
    auto wc=find_if(words.begin(),words.end(),bind(check_size,_1,sz));
}