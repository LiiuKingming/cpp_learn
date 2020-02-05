//leetcode 1. 两数之和
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;

        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }

        return ret;
        /*
        //哈希表一次遍历
        unordered_map<int, int> um;
        vector<int> ret;
        for(int i = 0; i < nums.size(); i++){
            int tmp = target - nums[i];
            
            if(um.find(tmp) != um.end()){
                ret.push_back(um[tmp]);
                ret.push_back(i);
                break;
            } else {
                um[nums[i]] = i;
            }
        }
        return ret;
        */
    }
};

//leetcode 67. 二进制求和
class Solution {
public:
    string addBinary(string a, string b) {
        string s;
        s.reserve(a.size() + b.size());
        int c = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1){
            c += i >= 0? a[i--] - '0' : 0;
            c += j >= 0? b[j--] - '0' : 0;
            s.push_back((c & 1) + '0');
            c >>= 1;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};