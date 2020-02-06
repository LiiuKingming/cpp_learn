//leetcode 125. 验证回文串
class Solution {
public:
    bool isLetterOrNum(char ch){
        return (ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z') ||
            (ch >= '0' && ch <= '9');
    }

    bool isSame(char a, char b){
        return (a == b) ||
            (a | 1 << 5 )== (b | 1 << 5);
    }

    bool isPalindrome(string s) {
        string tmp;
        for (auto & ch : s){
            if(isLetterOrNum(ch)){
                tmp.push_back(ch);
            }
        }

        int i, j;
        for (i = 0, j = tmp.size() - 1; i < j; i++, j--){
            if(!isSame(tmp[i], tmp[j])){
                return false;
            }
        }
        return true;
    }
};

//leetcode 443. 压缩字符串

class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() < 2){
            return chars.size();
        }

        int cur = 0;
        for(int i = 0, j = 0; j < chars.size(); i = j){
            while (j < chars.size() && chars[j] == chars[i]){
                j++;
            }
            chars[cur++] = chars[i];

            int count = j - i;
            if(count == 1){
                continue;
            } else {
                string s = to_string(count);
                for(int k = 0; k < s.size(); k++){
                    //s当中其实只有一个数字字符串
                    chars[cur++] = s[k];
                }
            }
        }
        return cur;
    }
};