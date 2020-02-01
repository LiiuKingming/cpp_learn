//leetcode 217.存在重复元素
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set s(nums.begin(), nums.end());
        return (s.size() != nums.size());
    }
};


//leetcode 925.长按键入
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int p = 0, pt1 = 0, pt2 = 0;
        while(name[p] != '\0'){
            while(name[p] != typed[pt1]){
                ++pt2;
                if(typed[pt2] == name[p]){
                    pt1 = pt2;
                } else if(typed[pt2] != name[p] && typed[pt2] == '\0'){
                    return false;
                }
            }
            ++p;
            ++pt1;
            ++pt2; 
        }
        return true;
    }
};