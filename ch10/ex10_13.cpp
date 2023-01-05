#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool StrLen5(const string& s){
    return s.length()>=5?true:false;
}

int main(){
    vector<string> vec;
    string s;
    auto iter=back_inserter(vec);
    while(cin>>s){
        *iter=s;
    }
    auto Less5=partition(vec.begin(),vec.end(),StrLen5);
    for(auto it=vec.begin();it!=Less5;++it){
        cout<<*it<<endl;
    }
}