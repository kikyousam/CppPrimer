#include <vector>
#include <iostream>

using std::cout;
using std::vector;
using Iter=vector<int>::iterator;

void print(Iter beg, Iter end){
    if(beg!=end){
        cout<<*beg<<" ";
        print(std::next(beg),end);
    }
}

int main(){
    vector<int> arr={1,2,3,4,5,5,6};
    print(arr.begin(),arr.end());
}