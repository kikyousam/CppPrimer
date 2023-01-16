// #ifndef EX12_19_H
// #define EX12_19_H

// #include <memory>
// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <string>
// #include <fstream>
// #include <exception>
// #include <initializer_list>

// using namespace std;

// class StrBlobPtr;

// class StrBlob{
// public:
//     friend class StrBlobPtr;
//     typedef vector<string>::size_type size_type;
//     StrBlob();
//     StrBlob(initializer_list<string> il);
//     size_type size() const {return data->size();}
//     bool empty() const { return data->empty(); }
//     void push_back(const string& t) {data->push_back(t);}
//     void pop_back();
//     //元素访问
//     string& front();
//     string& back();
//     const string& front() const
//     {
//         check(0, "front on empty StrBlob");
//         return data->front();
//     }
//     const string& back() const
//     {
//         check(0, "back on empty StrBlob");
//         return data->back();
//     }
//     StrBlobPtr begin() {}
//     StrBlobPtr end(){
//         // auto ret=StrBlobPtr(*this,data->size());
//         // return ret;
//     }
// private:
//     shared_ptr<vector<string>> data;
//     //如果data[i]不合法，抛出一个异常
//     void check(size_type i,const string &msg) const;
    
// };

// //构造函数
// StrBlob::StrBlob(): data(make_shared<vector<string>>()){}
// StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)){}

// void StrBlob::check(size_type i,const string & msg) const 
// {
//     if(i>=data->size()){
//         throw out_of_range(msg);
//     }
// }

// string& StrBlob::front(){
//     //如果vector为空，check会抛出一个异常
//     check(0,"front on empty StrBlob");
//     return data->front();
// }

// string& StrBlob::back(){
//     check(0,"back on empty StrBlob");
//     return data->back();
// }

// const string& StrBlob::front() const{
//     //如果vector为空，check会抛出一个异常
//     check(0,"front on empty StrBlob");
//     return data->front();
// }

// const string& StrBlob::back() const{
//     check(0,"back on empty StrBlob");
//     return data->back();
// }

// void StrBlob::pop_back(){
//     check(0,"pop_back on empty StrBlob");
//     data->pop_back();
// }

// //为StrBlob类定义一个伴随指针类,阻止一个用户访问不存在的vector的企图
// class StrBlobPtr{
// public:
//     StrBlobPtr():curr(0){};
//     StrBlobPtr(StrBlob &a, size_t sz=0):wptr(a.data),curr(sz){}
//     string& deref() const;
//     StrBlobPtr& incr();        //前缀递增

// private:
//     shared_ptr<vector<string>> check(size_t,const string& )const;
//     weak_ptr<vector<string>> wptr;
//     size_t curr ;
// };

// shared_ptr<vector<string>> StrBlobPtr::check(size_t i,const string& msg) const{
//     auto ret=wptr.lock();
//     if(!ret)
//         throw runtime_error("unbound StrBlobPtr");
//     if(i>=ret->size())
//         throw out_of_range(msg);
//     return ret;
// }

// //解引用StrBlobPtr
// string& StrBlobPtr::deref() const{
//     auto p = check(curr,"dereference past end");
//     return (*p)[curr];
// }

// //递增StrBlobPtr
// StrBlobPtr& StrBlobPtr::incr(){
//     //如果curr已经指向容器的尾后位置，就不能递增它
//     check(curr,"increment past end of StrBlobPtr");
//     ++curr;
//     return *this;
// }

// #endif


//  ex12_19.h
//  Exercise 12.19

//  Created by pezy on 12/26/14.
//  Copyright (c) 2014 pezy. All rights reserved.

//  Define your own version of StrBlobPtr and
//  update your StrBlob class with the appropriate friend declaration and begin
//  and end members.

//  @See    ex12_02.h

#ifndef EX12_19_H
#define EX12_19_H

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>

using std::vector;
using std::string;

class StrBlobPtr;

class StrBlob {
public:
    using size_type = vector<string>::size_type;
    friend class StrBlobPtr;

    StrBlobPtr begin();
    StrBlobPtr end();

    StrBlob() : data(std::make_shared<vector<string>>()) {}
    StrBlob(std::initializer_list<string> il)
        : data(std::make_shared<vector<string>>(il))
    {
    }

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const string& t) { data->push_back(t); }
    void pop_back()
    {
        check(0, "pop_back on empty StrBlob");
        data->pop_back();
    }

    std::string& front()
    {
        check(0, "front on empty StrBlob");
        return data->front();
    }

    std::string& back()
    {
        check(0, "back on empty StrBlob");
        return data->back();
    }

    const std::string& front() const
    {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    const std::string& back() const
    {
        check(0, "back on empty StrBlob");
        return data->back();
    }

private:
    void check(size_type i, const string& msg) const
    {
        if (i >= data->size()) throw std::out_of_range(msg);
    }

private:
    std::shared_ptr<vector<string>> data;
};

class StrBlobPtr {
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }
    string& deref() const
    {
        // auto p = check(curr, "dereference past end");
        // return (*p)[curr];
        return (*check(curr,"dereference past end"))[curr];
    }
    StrBlobPtr& incr()
    {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }

private:
    std::shared_ptr<vector<string>> check(size_t i, const string& msg) const
    {
        auto ret = wptr.lock();
        if (!ret) throw std::runtime_error("unbound StrBlobPtr");
        if (i >= ret->size()) throw std::out_of_range(msg);
        return ret;
    }
    std::weak_ptr<vector<string>> wptr;
    size_t curr;
};

#endif