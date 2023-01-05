#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <vector>
#include <numeric>

using namespace std;

int main(){
    // istream_iterator<int> int_it(cin);        //从cin读取int
    // istream_iterator<int> int_eof;            //尾后迭代器
    // ifstream in("afile");
    // istream_iterator<string> str_it(in);

    // istream_iterator<int> in_iter(cin);
    // istream_iterator<int> eof;
    // vector<int> vec;
    // while(in_iter!=eof){
    //     vec.push_back(*in_iter++);
    // }

    //写法2
    // istream_iterator<int> in_iter(cin),eof;
    // vector<int> vec(in_iter,eof);      //从迭代器范围构造vec

    // istream_iterator<int> in(cin),eof;
    // cout<<accumulate(in,eof,0)<<endl;

    vector<int> vec={1,2,3,4};
    ostream_iterator<int> out_iter(cout," ");
    // for(auto e : vec){
    //     *out_iter++=e;
    // }
    // cout<<endl;
    copy(vec.begin(),vec.end(),out_iter);
}