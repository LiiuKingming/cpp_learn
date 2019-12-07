//
// Created by 28943 on 2019/12/7.
//
//class Gift {
//public:
//    int getValue(vector<int> gifts, int n) {
//        // write code here
//        sort(gifts.begin(), gifts.end());
//        int mid = n / 2;
//        int count = 0;
//        for(int i = 0; i < gifts.size(); i++){
//            if(gifts[i] == gifts[mid]){
//                count++;
//            }
//        }
//        if(count > n / 2){
//            return gifts[mid];
//        } else {
//            return 0;
//        }
//    }
//};

#include <iostream>
#include <vector>
using namespace std;

int Array(vector<int> array) {
    int len = array.size();
    int* f = new int[len];
    //初始化
    f[0] = array[0];
    for(int i = 1;i < len;++i){
        f[i] = max(f[i - 1] + array[i], array[i]);
    }
    int Max = f[0];
    for(int i = 1; i < len; ++i){
        Max = max(Max, f[i]);
    }
    return Max;
}

int main(){
    int n = 0;
    cin >> n;
    int num = 0;
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> num;
        v.push_back(num);
    }
    cout << Array(v) << endl;
    return 0;
}