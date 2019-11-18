//
// Created by 28943 on 2019/11/18.
//
//-统计回文
//本题使用暴力求解方式计算即可，遍历str1，将str2 insert进入str1的每个位置，判断是否是回文，是就
//++count；需要注意的是这里不能 str1.insert(i, str2)，这样的话str1改变了，判断下一个位置就不对了。所
//以每次使用str1拷贝构造一个str，然后str.insert(i, str2)，再判断

#include<iostream>
#include<string>
using namespace std;
// 判断是否是回文
bool IsCircleText(const string& s){
    size_t begin = 0;
    size_t end = s.size()-1;
    while(begin < end){
        if(s[begin] != s[end])
            return false;

        ++begin;
        --end;
    }

    return true;
}

int main(){
    std::string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    size_t count = 0;
    for(size_t i = 0; i <= str1.size(); ++i){
        // 将字符串2插入到字符串1的每个位置，再判断是否是回文
        string str = str1;
        str.insert(i, str2);
        if(IsCircleText(str))
            ++count;
    }

    cout<<count<<endl;
    return 0;
}

//连续最大和
#include <iostream>
#include<vector>
using namespace std;
int main2()
{
    int size;
    cin >> size;
    vector<int> nums(size);
    for(size_t i = 0; i < size; ++i)
        cin >> nums[i];

    int result = nums[0];
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        // 计算到num[i]的子数组的最大和
        sum2 = sum1 >= 0 ? sum1+nums[i] : nums[i];
        if(sum2 > result)
            result = sum2;
        if(sum2 < 0)
            sum2 = 0;

        sum1 = sum2;
    }

    cout<<result<<endl;

    return 0;
}
