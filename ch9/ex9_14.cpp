#include <vector>
#include <list>
#include <iostream>

using namespace std;

int main(){
    list<char*> ilist={"a","ab","abc"};
    vector<string> ivector{"12","13","14"};
    ivector.assign(ilist.cbegin(),ilist.cend());
    for(auto it=ilist.cbegin();it!=ilist.cend();++it){
        std::cout<<*it<<endl;
    }
    for(auto it=ivector.cbegin();it!=ivector.cend();++it){
        std::cout<<*it<<endl;
    }
}