//leetcode 383.赎金信
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(magazine.size() < ransomNote.size())
            return false;
        int vb[26] = {0};

        for(int i = 0; i < magazine.size(); i++){
            ++vb[magazine[i] - 'a'];
        }

        for(int i = 0; i < ransomNote.size(); i++){
            if(--vb[ransomNote[i] - 'a'] < 0){
                return false;
            }
        }
        return true;   
    }
};

//leetcode 9.回文数
//判断前一半数字是否与后一半数字相等
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || x % 10 == 0 && x != 0){
            return false;
        }

        int reverseNum = 0;
        while(x > reverseNum){
            reverseNum = reverseNum * 10 + x % 10;
            x /= 10;
        }
        return x == reverseNum || x == reverseNum / 10;
    }
};