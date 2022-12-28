#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Screen{
public:
    typedef string::size_type pos;
    Screen()=default;
    Screen(pos ht,pos wd):height(ht),width(wd),contents(ht*wd,' '){}
    Screen(pos ht,pos wd, char c):height(ht),width(wd),contents(ht*wd,c){}
    char get() const{return contents[cursor];}
    inline char get(pos ht,pos wd) const;
    Screen &move(pos r,pos c);
    void some_member() const;
private:
    pos cursor=0;
    pos height = 0, width = 0;
    string contents;
    mutable size_t access_ctr;
};

inline   //可以在函数的定义处指定内联函数
Screen &Screen::move(pos r,pos c){
    pos row = r*width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r,pos c) const{
    pos row= r*width;
    return contents[row+c];
}

void Screen::some_member() const{
    ++access_ctr;
}


//窗口管理类
class Window_mgr{
public:
    typedef string::size_type pos;
    Window_mgr()=default;
private:
    vector<Screen> screens{Screen(24,80,' ')};
};