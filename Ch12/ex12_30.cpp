#include "tx12_3.h"
#include <fstream>
#include <iostream>


void runQueries(ifstream &is){
    TextQuery tq(is);
    while(true){
        cout<<"enter word to look for, or q to quit: ";
        string s;
        if(!(cin>>s)||s=="q") break;
        print(cout,tq.query(s))<<endl;
    }
}

int main(){
    ifstream file("data/storyDataFile");
    runQueries(file);
}