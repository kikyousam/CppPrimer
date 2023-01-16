#ifndef TX_12_3_H
#define TX_12_3_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <fstream>
#include <set>
#include <map>

using namespace std;
using line_no=vector<string>::size_type;



class QueryResult;
class TextQuery{
public:
    TextQuery(ifstream&);
    ~TextQuery(){}
    QueryResult query(const string& s) const;
private:
    shared_ptr<vector<string>> file;
    map<string,shared_ptr<set<line_no>>> wm;
};

class QueryResult{
friend ostream& print(ostream& ,const QueryResult&);
public:
QueryResult(string s,shared_ptr<set<line_no>> p,shared_ptr<vector<string>> f):
sought(s),lines(p),file(f){}

private:
    string sought;
    shared_ptr<set<line_no>> lines;
    shared_ptr<vector<string>> file;
};



#endif