#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <list>

using namespace std;



//定义StrBlob类
class StrBlob{
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const {return data->size();}
    bool empty() const { return data->empty(); }
    void push_back(const string& t) {data->push_back(t);}
    void pop_back();
    //元素访问
    string& front();
    string& back();

private:
    shared_ptr<vector<string>> data;
    //如果data[i]不合法，抛出一个异常
    void check(size_type i,const string &msg) const;
};

//构造函数
StrBlob::StrBlob(): data(make_shared<vector<string>>()){}
StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)){}

void StrBlob::check(size_type i,const string & msg) const 
{
    if(i>=data->size()){
        throw out_of_range(msg);
    }
}

string& StrBlob::front(){
    //如果vector为空，check会抛出一个异常
    check(0,"front on empty StrBlob");
    return data->front();
}

string& StrBlob::back(){
    check(0,"back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back(){
    check(0,"pop_back on empty StrBlob");
    data->pop_back();
}

int main(){
    //深拷贝
    vector<string> v1;
    {
        vector<string> v2={"a","an","the"};
        v1=v2;
    }
    // cout<<v1.size();
    //上面中v2对象被销毁，v1深拷贝v2,希望v2不被销毁
    // Blob<string> v1;
    // {
    //     Blob<string> v2={"a","an","the"};
    //     v1=v2;
    // }
    // cout<<v1.size();

    //12.1
    StrBlob b1;
    {
        StrBlob b2={"a","an","the"};
        b1=b2;
        b2.push_back("about");
    }
    cout<<b1.size()<<endl;
    // cout<<b2.size()<<endl;

}