#include "ex12_19.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc,char ** argv){
    StrBlob SB;
    ifstream input(argv[1]);
    if(input){
        string line;
        while(getline(input,line)){
            SB.push_back(line);
        }
    }else{
        cerr<<"couldn't open: "<<argv[1]<<endl;
    }
    for(auto beg=SB.begin();beg!=SB.end();beg.incr()){
        cout<<beg.deref()<<endl;
    }
}