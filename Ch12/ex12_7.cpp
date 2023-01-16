#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <memory>

using namespace std;

void input(shared_ptr<vector<int>>& p){
    istream_iterator<int> it(cin),eof;
    *p=vector<int>(it,eof);
}

void print(shared_ptr<vector<int>>& p){
    for_each(p->begin(),p->end(),[](const int a){
        cout<<a<<" ";
    });
}

int main(){
    shared_ptr<vector<int>> p=make_shared<vector<int>>();
    input(p);
    print(p);
}