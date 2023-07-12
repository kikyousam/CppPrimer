#ifndef EX13_5_H
#define EX13_5_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HasPtr{
public:
    HasPtr(const string& s=string()):
        ps(new string(s)){}
    HasPtr(HasPtr& orig):ps(new string(*orig.ps)),i(orig.i){}
private:
    string *ps;
    int i;
};

#endif

