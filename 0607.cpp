class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        int len = nums.size();
        int left, right, sum;
        if(len < 3) 
            return res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len; i++) {
            if(nums[i] > 0) 
                break;
            if(i>0 && nums[i] == nums[i-1]) 
                continue;
            left = i + 1;
            right = len - 1;
            while(left < right) {   
                sum = nums[i] + nums[left] + nums[right];
                if(sum == 0) {   
                    tmp = {nums[i], nums[left], nums[right]};
                    res.emplace_back(tmp);
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                }
                else if(sum > 0) 
                    right--;
                else 
                    left++;
            }
        }
        return res;

    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> tmp;
        int n = nums.size();
        int left, right, sum;
        if (n < 3)
            return ret;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            left = i + 1;
            right = n - 1;
            while (left < right) {
                sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    tmp = {nums[i], nums[left], nums[right]};
                    ret.push_back(tmp);
                    while (left < right && nums[left] == nums[left + 1])
                        ++left;
                    while (left < right && nums[right] == nums[right - 1])
                        --right; 
                    ++left;
                    --right;
                } else if (sum > 0) {
                    --right;
                } else if (sum < 0) {
                    ++left;
                }
            }
        }
        return ret;
    }
};