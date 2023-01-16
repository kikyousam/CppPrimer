#include <vector>
#include <iostream>
using namespace std;
int add(int a,int b){
    return a+b;
}
int del(int a,int b){
    return a-b;
}
int mul(int a,int b){
    return a*b;
}
int main(){
    int (*pf) (int,int);
    vector<decltype(pf)> arr;
    arr={&add,&del,&mul};
    cout<<arr[0](1,2)<<" "<<arr[1](1,2)<<" "<<arr[2](1,2)<<" "<<endl;
}