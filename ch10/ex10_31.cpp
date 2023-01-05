#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    istream_iterator<int> nin(cin),eof;
    vector<int> vec(nin,eof);
    sort(vec.begin(),vec.end());
    ostream_iterator<int> out(cout," ");
    unique_copy(vec.begin(),vec.end(),out);
}