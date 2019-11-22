//
// Created by 28943 on 2019/11/16.
//
//1. 考拉求字典序和字符串长度顺序

#include <iostream>
#include <vector>

using namespace std;
#if 1

int main(){
    int n = 0;
    cin >> n;
    string v;
    getline(cin, v);
    cout << v;

    return 0;
}
#else
//2. A 和 B最小公倍数
int yue(int a,int b){
    while(a!=b) {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }

}
int Commonmultiple(int a, int b){
    int ret = 0;
    if (a % b == 0){
        ret = a;
    } else if(b % a == 0){
        ret = b;
    } else {
        ret = a * b;
    }
    return ret;
}

int bei(int a,int b){
    return a/yue(a,b)*b;
}

int main(){
    int a = 0;
    int b = 0;
    cin >> a ;
    cin >> b ;
    cout << bei(a, b);
    return 0;
}



#endif