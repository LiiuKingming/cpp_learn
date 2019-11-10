//翻转一个字符串中的单词
#include<iostream>
#include<string>
using namespace std;

void reverseOneWord(string &s, int spos, int epos){
    int i, j;
    for(i = spos, j = epos - 1; i < j; i++, j--){
        swap(s[i], s[j]);
    }
}

int main(){
    string s1 = "I like BeiJing.";
    int spos = 0;
    int epos = s1.size() - 1;
    reverseOneWord(s1, spos, epos);
    epos = s1.find(' ');
    while(epos >= 0){
        reverseOneWord(s1, spos, epos);
        spos = epos + 1;
        epos = spos + s1.find(' ', spos);
    }
    reverseOneWord(s1, spos, s1.size());

    return 0;
}