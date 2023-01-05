#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool isShorter(const string& a,const string& b){
    return a.size()<b.size()?true:false;
}

void elimDumps(vector<string> &vec){
    sort(vec.begin(),vec.end());
    auto unique_end=unique(vec.begin(),vec.end());
    vec.erase(unique_end,vec.end());
    // stable_sort(vec.begin(),vec.end(),isShorter);
}

string make_plural(size_t ctr, const string &word,
                                const string &ending)
{
    return (ctr>1)?word+ending:word;
}

bool check_size(const string& s,vector<string>::size_type sz){
    return s.size()<=sz?true:false;
}

void biggies(vector<string> &words,vector<string>::size_type sz){
    // elimDumps(words);
    // stable_sort(words.begin(),words.end(),isShorter);
    // auto wc=stable_partition(words.begin(),words.end(),[sz](const string& s){return s.size()>=sz;});
    // auto count=wc-words.begin();
    // cout<<count<<" "<<make_plural(count,"word","s")
    //     <<" of length "<<sz<<" or longer"<<endl;
    // for_each(words.begin(),wc,[](const string& s){cout<<s<<" ";});

    // auto count=count_if(words.begin(),words.end(),[sz](const string& s){return s.size()>sz;});
    auto count=count_if(words.begin(),words.end(),bind(check_size,_1,sz));
    cout<<count<<" "<<make_plural(count,"word","s")
        <<" of length "<<sz<<" or shorter"<<endl;
    
}

int main(){
    vector<string> words={"aaaa","bbbbb","cccccccc","a","b","eeeeeeee","gfg","kajhdf"};
    biggies(words,6);
}