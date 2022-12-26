#include "ex7_12_sales_data.h"
#include <iostream>

int main(){
    Sales_data s1;
    Sales_data s2("0-201-70353-X");
    Sales_data s3("0-201-70353-X",4,24.99);
    Sales_data s4(std::cin);
    print(std::cout,s1)<<std::endl;
    print(std::cout,s2)<<std::endl;
    print(std::cout,s3)<<std::endl;
    print(std::cout,s4)<<std::endl;
}
// #include "ex7_11_sales_data.h"
// int main()
// {
//     Sales_data item1;
//     print(std::cout, item1) << std::endl;

//     Sales_data item2("0-201-78345-X");
//     print(std::cout, item2) << std::endl;

//     Sales_data item3("0-201-78345-X", 3, 20.00);
//     print(std::cout, item3) << std::endl;

//     Sales_data item4(std::cin);
//     print(std::cout, item4) << std::endl;
// }