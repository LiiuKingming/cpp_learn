class Solution {
public:
    string toLowerCase(string str) {
        if(str.empty())
            return str;
            
        for(auto &i : str){
            if(i >= 'A' && i <= 'Z'){
                i = i + 32;
            }
        }
        return str;
    }
};


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //反转
        if(nums.empty() || k < 0)
            return;
        
        reverse(nums.begin(), nums.end() - k % nums.size());
        reverse(nums.end() - k % nums.size(), nums.end());
        reverse(nums.begin(), nums.end());
    }
};