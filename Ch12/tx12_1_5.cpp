#include <memory>
#include <iostream>
#include <string>

using namespace std;

int main(){
    unique_ptr<string> p1(new string("SS"));
    unique_ptr<string> p2(p1.release());
    unique_ptr<string> p3(new string("ss"));
    p2.reset(p3.release());
}