#include "../Ch7/ex7_41_sales_data.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compareIsbn(const Sales_data& s1,const Sales_data& s2){
    return s1.isbn()<s2.isbn()?true:false;
}

int main(){
    Sales_data s1("a"),s2("b"),s3("c");
    vector<Sales_data> vec={s3,s2,s1};
    sort(vec.begin(),vec.end(),compareIsbn);
    for(auto &s:vec){
        print(cout,s);
        cout<<endl;
    }
}