//
// Created by 28943 on 2019/11/16.
//

//计算糖果
#include<iostream>
using namespace std;
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int A=(a+c)/2;
    int C=(d-b)/2;
    int B1=(c-a)/2;
    int B2=(b+d)/2;
    if(B1!=B2)
        cout<<"No";
    else
        cout<<A<<" "<<B1<<" "<<C;

    return 0;
}


//进制转换
// 题目的本意就是将10进制的数转换成N进制。N(2 ≤ N ≤ 16)可以看出进制最多可以到16进制

#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
int main2(){
    string s, table="0123456789ABCDEF";
    int m,n;
    cin>>m>>n;
    bool flag = false;

    // 如果是负数，则转成正数，并标记一下
    if(m < 0){
        m = 0 - m;
        flag = true;
    }

    // 按进制换算成对应的字符添加到s
    while(m){
        s += table[m%n];
        m /= n;
    }

    if(flag)
        s += '-';

    reverse(s.begin(), s.end());
    cout<<s<<endl;

    return 0;
}
