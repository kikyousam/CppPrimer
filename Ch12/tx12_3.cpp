#include "tx12_3.h"
#include <sstream>



TextQuery::TextQuery(ifstream& is):file(new vector<string>){
    string text;
    while(getline(is,text)){
        file->push_back(text);
        int n=file->size()-1;
        istringstream line(text);
        string word;
        while(line>>word){
            auto& lines=wm[word];    //注意这里的Lines是个引用，通过改变lines来改变wm中的元素
            if(!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string& sought) const{
    //如果未找到sought，我们将返回一个指向此set的指针
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    //使用find而不是下标运算符来查找单词，避免将单词添加到wm中！
    auto loc=wm.find(sought);
    if(loc==wm.end())
        return QueryResult(sought,nodata,file);
    else
        return QueryResult(sought,loc->second,file);
}

string make_plural(line_no n,string s1,string s2){
    return n>=2?s1:(s1+s2);
}

ostream &print(ostream & os,const QueryResult &qr){
    os<<qr.sought<<" occurs "<<qr.lines->size()<<" "
                <<make_plural(qr.lines->size(),"time","s")<<endl;
    for(auto num:*qr.lines){
        os<<"\t(line "<<num+1<<")"<<*(qr.file->begin()+num)<<endl;
    }
    return os;
}
