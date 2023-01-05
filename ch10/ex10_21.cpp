#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int i=9;
    auto f=[&i]()->bool{if(i!=0) {--i;return false;} else return true;};
    while(!f()){
        cout<<i<<endl;
    }
}