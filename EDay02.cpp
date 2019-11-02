//
// Created by 28943 on 2019/10/29.
//
//【倒置字符串】将一句话的单词进行倒置，标点不倒置。
// 比如 I like beijing. 经过函数后变为：beijing. like I

#include <iostream>
#include <string>
#include <vector>
using namespace std;
void reverseOneWord(string &s, int spos, int epos){
    int i, j;
    for(i = spos, j = epos - 1; i < j; i++, j--){
        swap(s[i], s[j]);
    }
}
string reserveWord(string &s1){
// s1 = "i Like beijing.";
    getline(cin, s1);
    int spos = 0;
    int epos = s1.size();
    reverseOneWord(s1, spos, epos);
    epos = s1.find(' ');
    while(epos >= 0 ){
// if(epos >= s1.size())
// break;
        reverseOneWord(s1, spos, epos);
        spos = epos + 1;
        epos = s1.find(' ', spos);
    }
    reverseOneWord(s1, spos, s1.size());
    return s1;
}
int main1(){
    string s1;
    reserveWord(s1);
    cout << s1;
    return 0;
}


//排序子序列
int main2() {
    int n;
    cin >> n;
    // 注意这里多给了一个值，是处理越界的情况的比较，具体参考上面的解题思路
    vector<int> a;
    a.resize(n + 1);
    a[n] = 0;
    //读入数组
    int i = 0;
    for (i = 0; i < n; ++i)
        cin >> a[i];
    i = 0;
    int count = 0;
    while (i < n) {
        // 非递减子序列
        if (a[i] < a[i + 1]) {
            while (i < n && a[i] <= a[i + 1])
                i++;
            count++;
            i++;
        } else if (a[i] == a[i + 1]) {
            i++;
        } else // 非递增子序列
        {
            while (i < n && a[i] >= a[i + 1])
                i++;
            count++;
            i++;
        }
    }
    cout << count << endl;
    return 0;
}
