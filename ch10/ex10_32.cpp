#include "Sales_item.h"
#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
    istream_iterator<Sales_item> item_iter(cin),eof;
    vector<Sales_item> vec;
    while(item_iter!=eof) vec.push_back(*item_iter++);
    sort(vec.begin(),vec.end(),[](const Sales_item& lhs,const Sales_item& rhs){
        return lhs.isbn()<rhs.isbn();
    });
    for(auto beg=vec.cbegin(),end=beg;beg!=vec.cend();beg=end){
        end=find_if(beg,vec.cend(),[&beg](const Sales_item& s){
            return beg->isbn()!=s.isbn();
        });
        cout<<accumulate(beg,end,Sales_item(beg->isbn()))<<endl;
    }
}
// int main()
// {
//     std::istream_iterator<Sales_item> in_iter(std::cin), in_eof;
//     std::vector<Sales_item> vec;

//     while (in_iter != in_eof) vec.push_back(*in_iter++);
//     sort(vec.begin(), vec.end(),
//          [](Sales_item const& lhs, Sales_item const& rhs) {
//              return lhs.isbn() < rhs.isbn();
//          });
//     for (auto beg = vec.cbegin(), end = beg; beg != vec.cend(); beg = end) {
//         end = find_if(beg, vec.cend(), [beg](const Sales_item& item) {
//             return item.isbn() != beg->isbn();
//         });
//         std::cout << std::accumulate(beg, end, Sales_item(beg->isbn()))
//                   << std::endl;
//     }
// }