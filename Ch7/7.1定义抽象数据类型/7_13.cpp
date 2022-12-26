#include "ex7_12_sales_data.h"

using namespace std;

int main(){
    Sales_data total(cin);
    if(!total.isbn().empty()){
        istream &is=cin;
        while(is){
            Sales_data trans(is);
            if(trans.isbn()==total.isbn()){
                total.combine(trans);
            }else{
                print(cout,total)<<endl;
                total=trans;
            }
        }
        print(cout,total)<<endl;
    }else{
        cerr<<" No data?!"<<endl;
    }
}