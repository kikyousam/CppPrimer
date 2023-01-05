#include "tx7_3_3screen.h"


int main(){
    Screen s1(10,10,'C');
    s1.move(4,0).set('%');
    Screen myscreen(5,5,'X');
    myscreen.move(4,0).set('#').display(cout);
    cout<<"\n";
    myscreen.display(cout);
    cout<<"\n";
}