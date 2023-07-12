#ifndef STRVEC_H
#define STRVEC_H

#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include <initializer_list>

using namespace std;

class StrVec{
public:
    StrVec():
        elements(nullptr),first_free(nullptr),cap(nullptr) {}
    StrVec(initializer_list<string> &il);
    StrVec(const StrVec&);
    StrVec &operator=(const StrVec&);
    ~StrVec();
    void push_back(const string&);        //拷贝元素
    size_t size() const { return first_free-elements; }
    size_t capacity() const { return cap - elements;}
    string *begin() const { return elements;}
    string *end() const { return first_free;}
    void reserve(size_t new_cap);
    void resize(size_t count);
    void resize(size_t count, const std::string&);

    std::string& at(size_t pos) { return *(elements + pos); }
    const std::string& at(size_t pos) const { return *(elements + pos); }

private:
    static allocator<string> alloc;       //分配元素
    //被添加元素的函数所使用
    void chk_n_alloc()
        { if(size()==capacity()) reallocate();}
    //工具函数，被拷贝构造函数、赋值运算符和析构函数所使用
    pair<string*,string*> alloc_n_copy
        (const string*,const string*);
    void free();             //创建元素并销毁内存
    void reallocate();       //获得更多的内存并拷贝已有元素
    void alloc_n_move(size_t new_cap);

    string* elements;        //指向数组首元素的指针
    string *first_free;      //指向数组第一个空闲元素的指针
    string *cap;            //指向数组尾后位置的指针

};



#endif