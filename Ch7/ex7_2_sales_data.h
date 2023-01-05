#include <iostream>
#include <string>

using std::string;

class Sales_data{
//
friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::istream &read(std::istream&,Sales_data&);
friend std::ostream &print(std::ostream& ,const Sales_data&);
public:
    Sales_data()=default;
    Sales_data(const string &s, unsigned n, double p):
        bookNo(s),units_sold(n),revenue(p*n){}
    Sales_data(const string& s):bookNo(s){}
    Sales_data(std::istream &);
    string isbn() const{return bookNo;}
    Sales_data &combine(const Sales_data&);

private:
    double avg_price() const
        { return units_sold? revenue/units_sold:0;}
    string bookNo;
    unsigned units_sold=0;
    double revenue=0.0;
};