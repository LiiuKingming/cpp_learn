//
// Created by 28943 on 2019/11/14.
//


#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

//1. 括号匹配字符串
#if 0
bool chkParenthesis(string &A, int n) {
    // write code here
    stack<char> s;
    for (auto &i : A) {
        if (i == '(') {
            s.push(i);
        } else  if (i == ')'){
            if( s.empty() == 1){
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}
int main(){
    int n = 0;
    string s;
    getline(cin, s);
    cin >> n;
    cout << chkParenthesis(s, n);

    return 0;
}
#endif

//2. 求几步++--可以得到斐波那契数
int Fibonacci(int n){
    //设置f1和f2保存最深两层数，f3储存更新数
    int f1 = 1;
    int f2 = 1;
    int f3 = 0;
    int i = 0;
    for (i = 3; i <= n; i++){
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    return f3;
}

int fibonacciNum(vector<int> &v, int n){
    int tmp = 0;
    for (int i = 0; i < v.size(); i++){
        v[i] = Fibonacci(i);
    }
    int min = v[v.size() - 1];
    for (auto &j : v){
        tmp = abs(n - j);
        if(tmp < min)
            min = tmp;
    }
    return min;
}

int main(){
//    int n = 0;
//    printf("请输入n:");
//    scanf("%d", &n);
//    int ret = Fibonacci( n );
//    printf("%d\n", ret);
    int N = 0;
    vector<int> v;
    v.resize(32);
    cin >> N;
    int res = fibonacciNum(v, N);
    cout << res;
    return 0;
}