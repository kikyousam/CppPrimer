#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool isShorter(const string& a,const string& b){
    return a.size()<b.size()?true:false;
}

int main(){
    vector<string> vec={"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
    sort(vec.begin(),vec.end());
    auto unique_end=unique(vec.begin(),vec.end());
    vec.erase(unique_end,vec.end());
    // for(auto s:vec){
    //     cout<<s<<" ";
    // }
    stable_sort(vec.begin(),vec.end(),isShorter);
    for(auto s:vec){
        cout<<s<<" ";
    }
}