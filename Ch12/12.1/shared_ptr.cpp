#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <list>

using namespace std;

int main(){
    shared_ptr<string> p1;     //shared_ptr指向string
    shared_ptr<list<int>> p2;   //shared_ptr指向list<int>>

    if(p1&&p1->empty())
        *p1="hi";
    if(p2&&p2->empty())
        p2=make_shared<list<int>>();
    
    shared_ptr<int> p3=make_shared<int>(4);
    shared_ptr<string> p4=make_shared<string>(5,'d');
    shared_ptr<int> p5 = make_shared<int> ();
    auto p6 = make_shared<int> (3);

    auto p = make_shared<int>(32);
    auto q(p);
    auto r = make_shared<int>(42);
    r=q;
}