#include <iostream>
#include <vector>

using namespace std;

inline const string& 
shorterString(const string& s1,const string &s2){
    return s1.size()<=s2.size()?s1:s2;
}

constexpr int new_sz() { return 42; }
constexpr int foo =new_sz();