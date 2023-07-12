#ifndef EX13_11_H
#define EX13_11_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HasPtr{
public:
    HasPtr(const string& s=string()):
        ps(new string(s)){}
    HasPtr(HasPtr& orig):ps(new string(*orig.ps)),i(orig.i){}
    ~HasPtr(){delete ps;}
private:
    string *ps;
    int i;
};

#endif

