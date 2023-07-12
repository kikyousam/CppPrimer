#include "ex13_31.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<HasPtr> v1;
    HasPtr hp1("dd"),hp2("aa"),hp3("cc"),hp4("bb");
    v1.push_back(hp1);
    v1.push_back(hp2);
    v1.push_back(hp3);
    v1.push_back(hp4);
    sort(v1.begin(),v1.end());
    // for(int i=0;i<4;++i){
    //     auto hp=v1[i];
    //     cout<<*hp.ps<<endl;
    // }
}