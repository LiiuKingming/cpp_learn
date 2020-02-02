//leetcode 905. 按奇偶排序数组
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        if(A.empty()){
            return A;
        }
        vector<int> tmp;

        for(int i = 0; i < A.size(); i++){
            if(A[i] % 2 == 0){
                tmp.push_back(A[i]);
            }
        }
        for(int i = 0; i < A.size(); i++){
            if(A[i] % 2 != 0){
                tmp.push_back(A[i]);
            }
        }
        tmp.swap(A);
        return A;
    }
};

//leetcode 724. 寻找数组的中心索引
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.empty()){
            return -1;
        }
        
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }

        int leftsum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(sum - nums[i] == 2 * leftsum){
                return i;
            }
            leftsum += nums[i];
        }
        return -1;
    }
};