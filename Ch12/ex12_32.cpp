#include <sstream>
#include "ex12_32.h"
#include <algorithm>
#include <cctype>
#include <ctype.h>

bool ispun(const char t){
    if((t>='a'&&t<='z')||t>='A'&&t<='Z')
        return false;
    else 
        return true;
}

TextQuery::TextQuery(ifstream& is):file(new StrBlob){
    StrBlob::size_type lineNo{0};
    for (string line; std::getline(is, line); ++lineNo) {
        file->push_back(line);
        std::istringstream line_stream(line);
        for (string text, word; line_stream >> text; word.clear()) {
            // avoid read a word followed by punctuation(such as: word, )
            std::remove_copy_if(text.begin(), text.end(),
                                std::back_inserter(word), ispun);
            // use reference avoid count of shared_ptr add.
            auto& nos = wm[word];
            if (!nos) nos.reset(new std::set<StrBlob::size_type>);
            nos->insert(lineNo);
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
        ConstStrBlobPtr p(*qr.file, num);
        os << "\t(line " << num + 1 << ") " << p.deref() << std::endl;
    }
    return os;
}
