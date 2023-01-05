#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Screen;

//窗口管理类
class Window_mgr{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
private:
    vector<Screen> screens{Screen(24,80,' ')};
};


class Screen{
// window_mgr的成员可以访问Screen类的私有成员
// friend class Window_mgr;
friend void Window_mgr::clear(ScreenIndex);
public:
    typedef string::size_type pos;
    Screen()=default;
    Screen(pos ht,pos wd):height(ht),width(wd),contents(ht*wd,' '){}
    Screen(pos ht,pos wd, char c):height(ht),width(wd),contents(ht*wd,c){}
    char get() const{return contents[cursor];}
    inline char get(pos ht,pos wd) const;
    Screen &move(pos r,pos c);
    void some_member() const;
    Screen &set(char);
    Screen &set(pos,pos,char);
    //根据对象是否是const重载了display函数
    Screen &display(std::ostream& os){
        do_display(os);
        return *this;
    }
    const Screen& display(ostream& os) const{
        do_display(os);
        return *this;
    }
private:
    pos cursor=0;
    pos height = 0, width = 0;
    string contents;
    mutable size_t access_ctr;
    //该函数负责显示screen的内容
    void do_display(std::ostream &os) const {os<<contents;}
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

inline Screen& Screen::set(char c){
    contents[cursor]=c;
    return *this;
}

inline Screen& Screen::set(pos r,pos col,char ch){
    contents[r*width+col] = ch;
    return *this;
}





void Window_mgr::clear(ScreenIndex i){
    Screen &s=screens[i];
    s.contents =string(s.height*s.width,' ');
}
