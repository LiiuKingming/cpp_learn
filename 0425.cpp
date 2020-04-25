class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findLargest(nums, k, 0, nums.size() - 1);
    }

    int findLargest(vector<int>& nums, int k, int left, int right) {
        if (left >= right)
            return nums[left];

        int pos = Partition(nums, left, right);
        if (pos == nums.size() - k) {
            return pos;
        } else if (pos < nums.size() - k) {
            return findLargest(nums, k, pos + 1, right);
        } else {
            return findLargest(nums, k, left, pos - 1);
        }
    }

    int Partition(vector<int>& nums, int start, int end) {
        int val = nums[start];
        int left = start;
        int right = end;
        
        while (left < right) {
            while (left < right && nums[right] > val){
                --right;
            }
            if (left < right) {
                nums[left++] = nums[right];
            }
            while (left < right && nums[left] < val) {
                ++left;
            }
            if (left < right) {
                nums[right--] = nums[left];
            }
        }
        nums[left] = val;
        return left;
    }
};
