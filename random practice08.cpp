//leetcode 66. 加一
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() - 1; i >= 0; i--){
            if(digits[i] == 9){
                digits[i] = 0;
            } else {
                digits[i]++;
                return digits;
            }
        }
        digits.push_back(0);
        digits[0] = 1;
        return digits;
    }
};

//leetcode 44. 第三大的数
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }

        set<int> s;
        for(auto &i : nums){
            s.insert(i);
            if(s.size() > 3){
                s.erase(*s.begin());
            }
        }
        if(s.size() < 3){
            return *s.rbegin();
        } else {
            return *s.begin();
        }
    }
};