#include <iostream>
#include <string>


using namespace std;

struct Person{
    string name;
    string address;

    string getName() const{ return name; };
    string getAddress() const {return address; };
};