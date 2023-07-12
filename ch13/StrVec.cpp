#include "StrVec.h"
#include <iostream>
#include <string>
#include <utility>
#include <initializer_list>

using namespace std;

void StrVec::push_back(const string& s){
    chk_n_alloc();       //确保有空间容纳新元素
    //在first_free指向的元素中构造s的副本
    alloc.construct(first_free++,s);
}

void StrVec::push_back(string&& s){
    chk_n_alloc();
    alloc.construct(first_free++,std::move(s));
}

pair<string*,string*>
StrVec::alloc_n_copy(const string* b,const string* e){
    //分配空间保存给定范围中的元素
    auto data=alloc.allocate(e-b);
    return {data,uninitialized_copy(b,e,data)};
}

void StrVec::free(){
    //不能传递deallocate一个空指针，如果elments未0，则函数什么都不做
    if(elements){
        //逆序销毁旧元素
        for(auto p=first_free;p!=elements;){
            alloc.destroy(--p);
        }
        alloc.deallocate(elements,cap-elements);
    }
}

StrVec::StrVec(const StrVec& s){
    //调用alloc_n_copy分配空间以容纳与s中一样多的元素
    auto newdata=alloc_n_copy(s.begin(),s.end());
    elements=newdata.first;
    first_free=cap=newdata.second;
}

StrVec::~StrVec() {free();};

StrVec& StrVec::operator=(const StrVec &rhs){
    //调用alloc_n_copy分配内存，大小与rhs中元素占用的空间一样多
    auto data=alloc_n_copy(rhs.begin(),rhs.end());
    free();
    elements=data.first;
    first_free=cap=data.second;
    return *this;
}

void StrVec::reallocate(){
    //我们将分配当前大小两倍的内存空间
    auto newcapacity = size()?2*size():1;
    //分配新内存
    auto newdata=alloc.allocate(newcapacity);
    //将数据从旧内存移动到新内存
    auto dest =newdata;        //指向新数组中下一个空闲位置
    auto elem= elements;       //指向旧数组中下一个元素
    for(size_t i=0;i!=size();++i){
        alloc.construct(dest++,std::move(*elem++));
    }
    free();
    //更新我们的数据结构，执行新元素
    elements=newdata;
    first_free=dest;
    cap=elements+newcapacity;
}

void StrVec::alloc_n_move(size_t n){
    auto newcapacity=n;
    auto newdata=alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for(size_t i=0;i!=size();++i){
        alloc.construct(dest++,std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free=dest;
    cap= elements+n;
}

void StrVec::reserve(size_t n){
    if(n>=capacity()){
        alloc_n_move(n);
    }
}

void StrVec::resize(size_t n){
    resize(n,string());
}

void StrVec::resize(size_t n,const string& s){
    if(n<size()){
        while(first_free!=elements+n) alloc.destroy(--first_free);
    }
    else if(n>size()){
        if(n>capacity()) reserve(n*2);
        for(size_t i=size();i!=n;++i){
            alloc.construct(++first_free,s);
        }
    }
}

StrVec::StrVec(initializer_list<string>& il){
    auto b=il.begin(),e=il.end();
    auto elements=alloc.allocate(e-b);
    first_free=cap=uninitialized_copy(b,e,elements);
}
