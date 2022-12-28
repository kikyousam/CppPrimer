#include <iostream>
#include <string>


using namespace std;

struct Person{
    string name;
    string address;

    string getName() const{ return name; };
    string getAddress() const {return address; };
    istream &read(istream& is, Person & p);
    ostream &print(ostream& os, const Person &p);
};

istream & Person::read(istream& is,Person &p){
    is>>p.name>>p.address;
    return is;
}

ostream& Person::print(ostream& os, const Person &p){
    os<<p.getName()<<" "<<p.getAddress();
    return os;
}