#include <iostream>
#include <string>

using std::string;
struct Sales_data;

std::istream &read(std::istream& ,Sales_data&);

struct Sales_data {
    //委托构造函数
    Sales_data(string s,unsigned cnt, double price):bookNo(s),units_sold(cnt),revenue(cnt*price) {}
    //其余构造函数全部委托另一个构造函数
    Sales_data():Sales_data("",0,0){}
    Sales_data(string s):Sales_data(s,0,0){}
    Sales_data(std::istream& is):Sales_data(){
        read(is,*this);
    }
    
    //新成员：关于Sales_data对象的操作
    std::string isbn() const {return bookNo;};
    Sales_data& combine(const Sales_data &);
    double avg_price() const;
    //数据成员和2.6.1节相比没有改变
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

//Sales_data 的非成员接口函数
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream& ,const Sales_data&);

inline
double Sales_data::avg_price() const {
    if(units_sold)
        return revenue/units_sold;
    else
        return 0;
}

Sales_data & Sales_data::combine(const Sales_data &rhs){
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

std::istream & read(std::istream& is,Sales_data& item){
    double price=0;
    is>>item.bookNo>>item.units_sold>>price;
    item.revenue=price*item.units_sold;
    return is;
}             

std::ostream &print(std::ostream &os,Sales_data& item){
    os<<item.isbn()<<" "<<item.units_sold<<" "
        <<item.revenue<<" "<<item.avg_price();
    return os;
}

