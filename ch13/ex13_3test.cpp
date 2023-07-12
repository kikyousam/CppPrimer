#include "../ch12/ex12_22.h"
#include <iostream>
using namespace std;


// test codes in main()
int main(){
    StrBlob str({"hello", "world"});
    std::cout << "before: " << str.count() << std::endl; // 1
    StrBlob str_cp(str);
    std::cout << "after: " << str.count() << std::endl;  // 2

    ConstStrBlobPtr p(str);
    std::cout << "before: " << p.count() << std::endl; // 2
    ConstStrBlobPtr p_cp(p);
    std::cout << "after: " << p.count() << std::endl; // 2
}
