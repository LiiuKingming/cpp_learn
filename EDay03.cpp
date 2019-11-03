//
// Created by 28943 on 2019/11/3.
//

//字符串中找出连续最长的数字串
#include<iostream>
#include<string>
#include <vector>
#include <algorithm>
using namespace std;
void FindNumArr(string &s){
    int len = 0;//最长数字串长度
    int count = 0;//当前数字串计数
    string tmp;
    string max;
    for (int i = 0; i < s.size(); ++i) {
        if ((s[i] >= '0' && s[i] <= '9')){
            tmp.push_back(s[i]);
            count++;
            if(count > len){
                len = count;
                max = tmp;
            }
        }else {
            count = 0;
            tmp.clear();
            continue;
        }
    }
    for(auto &i : max){
        cout << i;
    }
}
int main1(){
    string s;
    getline(cin, s);
    FindNumArr(s);
// cout << s;
    return 0;
}

//数组中出现次数超过一半的数字
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int icount = 1;
        int num = numbers[0];
        int i;
        for(i = 1; i < numbers.size() ;i++){
            if(numbers[i] == numbers[i - 1]){
                icount++;
            }else{
                if(icount <= 1){
                    num = numbers[i];
                }else{
                    icount--;
                }
            }
        }
    //#include <algorithm> begin->end中num出现的次数
        if((numbers.size() / 2) < count(numbers.begin(), numbers.end(), num)) {
            return num;
        }
        return 0;
    }
};
