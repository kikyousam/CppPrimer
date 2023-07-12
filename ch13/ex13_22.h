#ifndef EX13_22_H
#define EX13_22_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HasPtr{
public:
    HasPtr(const string& s=string()):
        ps(new string(s)){}
    HasPtr(HasPtr& orig):ps(new string(*orig.ps)),i(orig.i){}
    HasPtr& operator=(const HasPtr& orig){
        auto newp=new string(*orig.ps);
        delete ps;
        ps=newp;
        i=orig.i;
        return *this;
    }
private:
    string *ps;
    int i;
};

#endif

