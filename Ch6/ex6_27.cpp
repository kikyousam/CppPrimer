#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int add(initializer_list<int> il){
    return accumulate(il.begin(),il.end(),0);
}

int main(){
    cout<<add({1,2})<<endl;
    cout<<add({1,2,3})<<endl;
}