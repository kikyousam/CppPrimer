#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(){
    const char *c1 = "Hello ";
	const char *c2 = "World";
	unsigned len = strlen(c1) + strlen(c2) + 1;
	char *r = new char[len]();
	strcat_s(r, len, c1);
	strcat_s(r, len, c2);
	std::cout << r << std::endl;
    // string s1="123";
    // string s2="abc";
    // string  ss=new string;
    // for(char* cp=c1;cp!=c1+sizeof(c1);++cp){
    //     *cs=*cp;
    // }
    // for(char *cp=c2;cp!=c2+sizeof(c2);++cp){
    //     *cs=*cp;
    // }
    std::string s1 = "Hello ";
	std::string s2 = "World";
	strcpy_s(r, len, (s1 + s2).c_str());
	std::cout << r << std::endl;

	delete[] r;
}