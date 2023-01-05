#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    istream_iterator<string> is(cin),eof;
    vector<string> vec(is,eof);
    ostream_iterator<string> out(cout," ");
    copy(vec.begin(),vec.end(),out);
}