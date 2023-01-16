#ifndef TX_12_33_H
#define TX_12_33_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <fstream>
#include <set>
#include <map>
#include <initializer_list>
#include <exception>
#include <iterator>
#include "ex12_22.h"

using namespace std;
using line_no=StrBlob::size_type;

class QueryResult;
class TextQuery{
public:
    TextQuery(ifstream&);
    ~TextQuery(){}
    QueryResult query(const string& s) const;
private:
    shared_ptr<StrBlob> file;
    map<string,shared_ptr<set<line_no>>> wm;
};

class QueryResult{
public:
    friend ostream& print(ostream& ,const QueryResult&);
    using ResultIter=set<StrBlob::size_type>::iterator;
public:
QueryResult(string s,shared_ptr<set<line_no>> p,shared_ptr<StrBlob> f):
sought(s),lines(p),file(f){}
    ResultIter begin() const { return lines->begin(); }
    ResultIter end() const { return lines->end(); }
    shared_ptr<StrBlob> get_file() const {return file;}

private:
    string sought;
    shared_ptr<set<line_no>> lines;
    shared_ptr<StrBlob> file;
};

#endif