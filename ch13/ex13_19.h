//
//  ex13_18.h
//  Exercise 13.18
//
//  Created by pezy on 1/15/15.
//  Copyright (c) 2015 pezy. All rights reserved.
//
//  Define an Employee class that contains an employee name and a unique
//  employee identifier.
//  Give the class a default constructor and a constructor that
//  takes a string representing the employee’s name.
//  Each constructor should generate a unique ID by incrementing a static data
//  member.
//

#ifndef CP5_ex13_19_h
#define CP5_ex13_19_h

#include <string>
using std::string;

class Employee {
public:
    Employee();
    Employee(const string& name);

    Employee(const Employee&)=delete;
    Employee& operator=(const Employee&) =delete;

    const int id() const { return id_; }

private:
    string name_;
    int id_;
    static int s_increment;
};

#endif