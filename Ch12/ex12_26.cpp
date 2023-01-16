#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main(){
    const int n=5;
    allocator<string> alloc;
    auto p=alloc.allocate(n);
    auto q=p;
    string s;
    while(cin>>s&&q!=p+n)
        alloc.construct(q++,s);
    const size_t size = q-p;
    cout<<size<<endl;
    alloc.deallocate(p,n);
}