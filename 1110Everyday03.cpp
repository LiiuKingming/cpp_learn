//�����г��ִ�������һ�������
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
        //#include <algorithm>  begin->end��num���ֵĴ���
        if((numbers.size() / 2) < count(numbers.begin(), numbers.end(), num)) {
            return num;
        }
        return 0;
        }
};


//�ַ���������ִ�:

#include<iostream>
#include<string>

using namespace std;


void FindNumArr(string &s){
    int len = 0;//����ִ�����
    int count = 0;//��ǰ���ִ�����
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
        } else {
            count = 0;
            tmp.clear();
            continue;
        }
    }
    for(auto &i : max){
        cout << i;
    }
}


int main(){
    string s;
    getline(cin, s);
    FindNumArr(s);
    return 0;
}