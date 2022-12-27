#ifndef EX7_15_H
#define EX7_15_H


#include <iostream>
#include <string>


using namespace std;

struct Person;

istream &read(istream& is, Person & p);

struct Person{
    Person()=default;
    Person(string &na,string& ad):name(na),address(ad){};
    Person(istream& is){
        read(is,*this);
    }
    string name;
    string address;

    string getName() const{ return name; };
    string getAddress() const {return address; };
    
    
};

ostream &print(ostream& os, const Person &p);

istream & read(istream& is,Person &p){
    is>>p.name>>p.address;
    return is;
}

ostream& print(ostream& os, const Person &p){
    os<<p.getName()<<" "<<p.getAddress();
    return os;
}

#endif