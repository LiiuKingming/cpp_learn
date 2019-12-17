//
// Created by 28943 on 2019/12/9.
//
//猴子分桃子
#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n == 0)
            break;
        else {
            cout <<(long)pow(5, n) - 4 <<" "<< (long)pow(4, n) + n - 4 << endl;
        }
    }
    return 0;
}
//奇数位都是奇数或偶数位都是偶数
//该题有缺陷
class Solution {
public:
    void oddInOddEvenInEven(std::vector<int>& arr, int len) {
        long i = 0, j = 1;
        while(i < len && j < len){
            if((arr[i] % 2) == 0) { i += 2; continue; }//偶数位上寻找非偶数
            if((arr[j] % 2) != 0) { j += 2; continue; }//奇数位上寻找非奇数
            swap(arr[i], arr[j]);
        }
    }
};