//
// Created by 28943 on 2019/11/28.
//
/*
#include <stdio.h>
int BuySoda(int soda){
    static int bottle = 0;
    if(soda * 2 + bottle < 2){//判断是否有剩下一个空瓶
        return 0;
    }
    if(soda % 2 == 0){//所有空瓶兑换汽水
        return soda + BuySoda(soda / 2);
    }else if(soda % 2 == 1 && bottle == 0){//空瓶兑换完剩下一个瓶子
        bottle++;
        return soda + BuySoda(soda / 2);
    }else if(soda % 2 == 1 && bottle == 1){//空瓶兑换完剩一个,此前剩一个刚好加起来兑换一瓶汽水
        bottle--;
        return soda+BuySoda(soda / 2 + 1);
    }
}
int main(){
    int money=20;
    int num=BuySoda(money);
    printf("%d\n",num);
    return 0;
}
 */
//换汽水
#if 1
#include <iostream>
using namespace std;
int BuySoda(int soda){
    return soda / 2;
}
int main(){
    int Bottle = 0;
    while (cin >> Bottle) {
        cout << BuySoda(Bottle) << endl;
    }
}
#else
//ab字符串公共最长子串
#include <iostream>
#include <string>
using namespace std;

string publicChildStr(string &a, string &b){
    static string child;
    static string tmp;
    for (size_t i = 0; i < a.size(); i++){
        for(size_t j = 0; j < b.size(); j++){
            if(a[i] == b[j] && a[i + 1] == b[j + 1]){
                tmp.push_back(a[i]);
                break;
            }else if(a[i] == b[j] && a[i + 1] != b[j + 1]){
                tmp.push_back(a[i]);
                child = tmp;
                tmp.clear();
                break;
            }
        }
    }
    return child;
}
int main(){
    string a;
    string b;
    while (cin >> a >> b){
    cout << publicChildStr(a, b) << endl;
    }
    return 0;
}
#endif