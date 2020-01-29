class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();
        int i = 0, j = 0;
        
        while(j < length){
            if(nums[j] != val){
                nums[i] = nums[j];
                ++i;
                ++j;
            } else {
                ++j;
            }
        }
        return nums.size() - (j - i);
       // return i;
    }
};

#include <algorithm>
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()){
            return -1;
        }

        if(nums[nums.size() - 1] < target){
            return nums.size();
        }

        int left = 0;
        int right = nums.size() - 1;
        while(left < right){
            //int mid = left + (right - left) / 2;
            int mid = (left + right) / 2;

            if(target <= nums[mid]){
                //左边
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};