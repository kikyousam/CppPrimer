#include <iostream>
#include <string>

using namespace std;

struct First{
    int memi;
    int getMem();
};

struct Second{
    int memi;
    int getMem();
};

First obj1;
// Second obj2=obj1;

struct Y;
struct X{
    Y* py;
};
struct Y{
    X x;
};
