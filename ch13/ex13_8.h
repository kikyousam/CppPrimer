#ifndef EX13_8_H
#define EX13_8_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HasPtr{
public:
    HasPtr(const string& s=string()):
        ps(new string(s)){}
    HasPtr(HasPtr& orig):ps(new string(*orig.ps)),i(orig.i){}
    HasPtr& operator=(const HasPtr& hp){
        std::string* new_ps = new std::string(*hp.ps);
        delete ps;
        ps = new_ps;
        i = hp.i;
        return *this;
    }
private:
    string *ps;
    int i;
};

#endif