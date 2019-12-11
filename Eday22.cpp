//
// Created by 28943 on 2019/12/2.
//
//1. 第一个只出现一次的字符

#include <iostream>
#include <set>
#include <vector>
using namespace std;
/*
int main(){
    string s;
    while(cin >> s){
        int arr[100] = {0};
        for(auto &i :s){
            ++arr[i];
        }
        int j;
        for (j = 0; j < s.size(); j++){
            if(arr[s[j]] == 1){
                cout << s[j] << endl;
                break;
            }
        }
        if (j >= s.size())
            cout << -1 << endl;
    }
    return 0;
}
*/

//小易打怪兽
int GCD(int a, int b){
    int c;
    while (c = a % b){
        a = b;
        b = c;
    }
    return b;
}

int main(){
    int n, power;
    vector<int> num;
    while (cin >> n >> power){
        num.resize(n);
        for (int i = 0; i < n; i++){
            cin >> num[i];}
        for (int k = 0; k < n; k++){
            if (num[k] < power){
                power += num[k];
            } else {
                power += GCD(power, num[k]);
            }
        }
        cout << power << endl;
    }
    return 0;
}
