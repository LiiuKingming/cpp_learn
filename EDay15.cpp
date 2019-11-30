//
// Created by 28943 on 2019/11/22.
//

#include <iostream>
#include <vector>
using namespace std;
//1. 二进制1的位数
#if 1
static int findNumberOf1(size_t num){
    int count = 0;
    size_t tmp = 0;
    for (int i = 31; i >= 0; i--){
        tmp = (num >> i) & 1;
        if (tmp == 1)
            count++;
    }
    return count;
}
#else
int findMinimum(int n, vector<int> &left, vector<int> &right) {
    // write code here
    int left_sum = 0, left_min = INT_MAX;
    int right_sum = 0, right_min = INT_MAX;
    int sum = 0;
    //遍历每一种颜色的左右手套序列
    for(int i=0;i<n;i++){
        //对于有0存在的颜色手套，累加
        if(left[i]*right[i]==0)
        sum += left[i] + right[i];
        //对于左右手都有的颜色手套，执行累加-最小值+1
        //找到最小值和总数
        else{
            left_sum += left[i];
            right_sum += right[i];
            left_min = min(left_min, left[i]);
            right_min = min(right_min, right[i]);
        }
    }
    //结果为有左右都有数量的手套序列的结果+有0存在的手套数+最后再加一肯定就能保证了
    return sum + min(left_sum-left_min+1, right_sum-right_min+1) + 1;
}
#endif
int main(){
//    int n = 0;
//    vector<int> left(0);
//    vector<int> right(0);
//    findMinimum(n, left, right);
    size_t num = 0;
    while (cin >> num){
        cout << findNumberOf1(num) << endl;
    }
    return 0;
}