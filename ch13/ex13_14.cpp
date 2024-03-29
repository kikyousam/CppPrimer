//
//  ex13_17.cpp
//  Exercise 13.17
//
//  Created by pezy on 1/15/15.
//  Copyright (c) 2015 pezy. All rights reserved.
//
//  Write versions of numbered and f corresponding to the previous three
//  exercises
//  and check whether you correctly predicted the output.
//
//  For 13.14

#include <iostream>

class numbered {
public:
    numbered()
    {
        static int unique = 10;
        mysn = unique++;
    }

    int mysn;
};

void f(numbered s)
{
    std::cout << s.mysn << std::endl;
}

int main()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
}

// output
// 10
// 10
// 10