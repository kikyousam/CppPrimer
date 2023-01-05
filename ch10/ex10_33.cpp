#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

int main(int argc,char** argv){
    ifstream file_in(argv[1]);
    istream_iterator<int> iter_in(file_in),eof;
    ofstream file_out1(argv[2]),file_out2(argv[3]);
    ostream_iterator<int> iter_out1(file_out1," "),iter_out2(file_out2,"\n");
    while(iter_in!=eof){
        if(*iter_in%2==1)
            *iter_out1=*iter_in;
        else
            *iter_out2=*iter_in;
        ++iter_in;
    }
}