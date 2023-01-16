#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void input(vector<int>* p,istream& is){
    istream_iterator<int> it(is),eof;
    *p=vector<int>(it,eof);
}

void print(vector<int>* p){
    for_each(p->begin(),p->end(),[](const int a){
        cout<<a<<" ";
    });
}

int main(){
    vector<int>* p=new vector<int>();
    input(p,cin);
    print(p);
    delete p;
}