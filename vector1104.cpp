//
// Created by 28943 on 2019/11/4.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//C版本杨辉三角
void printArray(const vector<int> &v, int n){
    for(int i = 0; i < n; i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}
void printGenerate(int n){//C版本杨辉三角
    vector<int> v(n, 0);
    v[0] = 1;//影子
    printArray(v, 1);

    int i, j;
    for(i = 0; i < n; i++){
        for(j = i; j > 0; j--){
            v[j] += v[j - 1];
        }
        printArray(v, i + 1);
    }
}
//杨辉三角
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> data(numRows);
    if(numRows == 0){
        return data;
    }
    int i, j;
    data[0].push_back(1);//种子
    for(i = 1; i < numRows; i++){
        data[i] = data[i - 1];
        for(j = i - 1; j > 0; j--){
            data[i][j] += data[i][j - 1];
        }
        data[i].push_back(1);
    }
    return data;
}

int _singleNumber(vector<int>& nums) {//方法1
    int sum = 0, tmp = 0;
    for(auto &i : nums){
        sum = (sum ^ i) & (~tmp);
        tmp = (tmp ^ i) & (~sum);
    }
    return sum;
}
int singleNumber(vector<int>& nums) {//方法2
    int sum = 0, count = 0;
    int  i;
    for(i = 0; i < 32; i++){
        for(auto &j : nums){
            count += j >> i & 1u;//1u->unsigned
        }
        if(count % 3){
            sum |= 1u << i;
        }
        count = 0;
    }
    return sum;
}

int MoreThanHalfNum_Solution(const vector<int> &numbers) {//加const和&更快, 不用拷贝
    int icount = 1;
    int num = numbers[0];

    int i;
    for(i = 0; i < numbers.size() ;i++){
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
    //#include <algorithm>  begin->end中num出现的次数
    if((numbers.size() / 2) < count(numbers.begin(), numbers.end(), num)) {
        return num;
    }
    return 0;
}

namespace _tmp{
    string numLetter[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
}

 void dealLetterCombinations(string &digits, size_t pos, vector<string> &alldata){//元素, 层数, alldata所有情况
    static string res = digits;//存结果, 不能随着栈消失

    if(pos < digits.size()){
        for(auto &i : _tmp::numLetter[digits[pos] - '2']){
            //_tmp::numLetter[digits[pos] - '2']是string的元素, 对其进行遍历
            res[pos] = i;//覆盖字符 如abc
            dealLetterCombinations(digits, pos + 1, alldata);
        }
    }else{//数字填完, 放入res
        cout << res <<endl;
        alldata.push_back(res);

    }
//    _tmp::numLetter[digits[pos] - '2'];
}
vector<string> letterCombinations(string digits) {
    vector<string> res;

    dealLetterCombinations(digits, 0, res);
    return res;
}

int FindGreatestSumOfSubArray_1(vector<int> array) {
    int tmp = array[0];
//    vector<int> tmp(array.size(), 0);
    int maxPre = array[0];

    int i;
    for(i = 0; i < array.size(); i++){
        if(maxPre > 0){//maxPre + array[i] > array[i]
            maxPre += array[i];
        }else{
            maxPre = array[i];
        }
        if(tmp < maxPre){
            tmp = maxPre;
        }
    }
    return tmp;
}

int dealGreatestSum(vector<int> &array, int begin, int end){
    if(begin == end){
        return array[begin];
    }
    int mid = (begin + end) / 2;
    int leftMax = dealGreatestSum(array, begin, mid);
    int rightMax = dealGreatestSum(array, mid + 1, end);

    int crossMax = 0;
    int i;
    int sum = 0;
    int tmpMax = array[mid];//极大值
    for (i = mid; i >= begin ; i--) {
        sum += array[i];
        if(sum > tmpMax){
            tmpMax = sum;
        }
    }

    crossMax += tmpMax;
    sum = 0;
    tmpMax = array[mid + 1];
    for(i = mid + 1; i <= end; i++){
        sum += array[i];
        if(sum > tmpMax){
            tmpMax = sum;
        }
    }
    crossMax += tmpMax;
    return max(max(leftMax, rightMax), crossMax);
}
int FindGreatestSumOfSubArray_2(vector<int> array) {
    return dealGreatestSum(array, 0, array.size() - 1);
}

int main(){
    string digits = "2333";
    vector<string> data = letterCombinations(digits);

    /*int nums[10] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5};
    vector<int> v;
    v.insert(v.begin(), nums, nums + 10);

    cout << singleNumber(v) << endl;*/

    /*vector<vector<int>> data = generate(10);
    for(auto &i : data){
        for(auto &j : i){
            cout << j << ' ';
        }
        cout << endl;
    }*/
    return 0;
}

