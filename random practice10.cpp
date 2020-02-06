//leetcode 8.字符串转换整数
class Solution {
public:
    int myAtoi(string str) {
        int flag = 1;
        int i = 0;
        int res = 0;
        
        while (str[i] == ' '){
            i++;
        }

        if (str[i] == '-'){
            flag = -1;
        }
        if (str[i] == '+' || str[i] == '-'){
            i++;
        }

        while (i < str.size() && (str[i] >= '0' && str[i] <= '9')){
            int tmp = str[i] - '0';
            if(res > INT_MAX / 10 || res == INT_MAX /10 && tmp > 7){
                return flag > 0? INT_MAX : INT_MIN;
            }
            res = res * 10 + tmp;
            i++;
        }
        return flag > 0? res : -res;
    }
};

//leetcode 34.在排序数组中查找元素的第一个和最后一个位置

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = -1, end = -1;
        for(int i = 0; i < nums.size(); i++){
                if(start == -1 && nums[i] == target){
                start = i;
            }
            if(nums[i] == target){
                end = i;
            }
        }
        vector<int> v;
        v.push_back(start);
        v.push_back(end);
        return v;
    }
};