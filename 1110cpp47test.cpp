//
// Created by 28943 on 2019/11/12.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
//1. 输出字符串中出现过的字符
//法2 bitmap 查找复杂度O(1)  遍历复杂度O(N)
static int g_blbitmap = 0;
static int g_slbitmap = 0;

void setbit(char ch){
    if (ch <= 'Z' && ch >= 'A'){
        g_blbitmap |= 1 << (ch -'A');
    } else {
        g_slbitmap |= 1 << (ch -'a');
    }
}

bool find(char ch){
    if (ch <= 'Z' && ch >= 'A'){
        return (g_blbitmap >> ch -'A') & 1;
    } else {
        return (g_blbitmap >> ch -'a') & 1;
    }
}



int main1(){

    char tmp[101] = {0};
    cin >> tmp;
    string src(tmp);
    string dst;
    //法1 查找复杂度O(N) 遍历复杂度O(N)
//    for(auto &ch : src){
//        if(dst.find(ch) == -1){//没找到
//            dst.push_back(ch);
//        }
//    }

    for(auto &ch : src){
        if(!find(ch)){
            dst.push_back(ch);
        }
        setbit(ch);
    }

    cout << dst;
    return 0;
}
*/
//2. 元素查找

int findBreakPoint(const vector<int> &src){
    int left = 0;
    int right = src.size() - 1;
    int mid;

    while (left <= right){
        mid = (left + right) / 2;
        if (src[mid] > src[mid + 1]){//找到断点位置
            return mid + 1;
        }
        if(src[left] > src[mid]){
            right = mid -1;
        } else {
            left = mid + 1;
        }
    }
}

int bfind(const vector<int> &src, int bp, int n){
    int size = src.size();
    int left = bp;
    int right = bp + size;
    int mid;

    while( left <= right){
        mid = (left + right) / 2;
        if (src[mid % size] > n){
            right = mid - 1;
        }else if(src[mid % size] < n){
            left = mid + 1;
        } else {
            return mid % size;
        }
    }
}

int main(){
    vector<int> src{7, 8, 9, 1, 2, 3, 4, 5, 6};
    int breakpoint =  findBreakPoint(src);
    cout << bfind(src, breakpoint, 9);
    return 0;
}