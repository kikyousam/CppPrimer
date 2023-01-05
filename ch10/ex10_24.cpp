#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>

using namespace std;
using namespace placeholders;

bool check_size(const string& s,int sz){
    return sz>s.size()?true:false;
}

int main(){
    vector<int> arr={1,2,3,4,5,6,7};
    const string s="abc";
    auto first=find_if(arr.begin(),arr.end(),bind(check_size,s,_1));
    cout<<*first<<endl;
}