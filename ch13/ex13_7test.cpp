#include "../ch12/ex12_22.h"
#include <iostream>
using namespace std;


// test codes in main()
int main(){
    StrBlob str({"hello", "world"}),str_cp;
    std::cout << "before: " << str.count() << std::endl; // 1
    str_cp=str;
    std::cout << "after: " << str.count() << std::endl;  // 2

    ConstStrBlobPtr p(str),p_cp;
    std::cout << "before: " << p.count() << std::endl; // 2
    p_cp=p;
    std::cout << "after: " << p.count() << std::endl; // 2
}
