//
// Created by 28943 on 2019/11/13.
//
//二货放蛋糕
/*
#include <iostream>
#include <cmath>

using namespace std;

int howNumCake(int w, int h){
    int res = 0;
    int x1, y1, x2, y2;
    for (x1 = 0, x2 = 0; x1 < w, x2 < w; x1++, x2++ ){
        for (y1 = 0, y2 = 0; y1 < h, y2 < h; y1++, y2++ ) {
            if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) == 4){
                res++;
            }
        }
    }
    return res;
}


int main(){
    int w = 0;
    int h = 0;
    int res = 0;
    scanf("%d %d", &w, &h);
    res = howNumCake(w, h);
    cout << res;
    return 0;
}
*/
//1.
//二货小易有一个W*H的网格盒子，网格的行编号为0~H-1，网格的列编号为0~W-1。每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能等于2。
//对于两个格子坐标(x1,y1),(x2,y2)的欧几里得距离为:
//   ( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) ) 的算术平方根
//        小易想知道最多可以放多少块蛋糕在网格盒子里。
//
// 使用vector<vector<int>>定义一个二维数组，resize开 空间并初始化，
// 每个位置初始化为1，表示当蛋糕，a[i][j]位置放蛋糕，
// 则可以标记处a[i][j+2]和a[i+1][j]位置 不能放蛋糕，
// 遍历一遍二维数组，标记处不能放蛋糕的位置，统计也就统计出了当蛋糕的位置数

#if 0
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int w,h,res = 0;
    cin >> w >> h;
    vector<vector<int>> a;
    a.resize(w);
    for(auto& e : a)
        e.resize(h, 1);
    for(int i=0;i<w;i++){
        for(int j=0;j<h;j++){
            if(a[i][j]==1){
                res++;
                // 标记不能放蛋糕的位置
                if((i+2)<w)
                    a[i+2][j] = 0;
                if((j+2)<h)
                    a[i][j+2] = 0;
            }
        }
    }
    cout << res;
    return 0;
}
#endif
//将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。
// 数值为0或者字符串不是一个合法的数值则返回0

//本题本质是模拟实现实现C库函数atoi，不过参数给的string对象

//解题思路非常简单，就是上次计算的结果*10，相当于10进制进位，然后加当前位的值。
//例如：“123”转换的结果是 sum=0
// sum*10+1->1
// sum*10+2->12
// sum*10+3->123
//本题的关键是要处理几个关键边界条件：
// 1. 空字符串
// 2. 正负号处理
// 3. 数字串中存在非法字

#if 0
class Solution {
public:
    int StrToInt(string str){
        if(str.empty())
            return 0;
        int symbol = 1;
        if(str[0] == '-'){  //处理负号
            symbol = -1;
            str[0] = '0'; //这里是字符'0',不是0
            }
        else if(str[0] == '+') {//处理正号

            symbol = 1;
            str[0] = '0';
        }
        int sum = 0;
        for(int i=0;i<str.size();++i){
            if(str[i] < '0' || str[i] > '9'){
                sum = 0;
                break;
            }
            sum = sum *10 + str[i] - '0';
        }        return symbol * sum;
    }
};
#endif