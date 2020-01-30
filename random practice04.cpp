//leetcode 58.最后一个单词长度
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty()){
            return 0;
        }

        int begin = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] != ' '){
                begin = i;
                break;
            }
        }

        int count = 0;
        for(int i = begin; i >= 0; i--){
            if(s[i] != ' '){
                count++;
            } else {
                break;
            }
        }
        return count;
    }
};

//leetcode 88.合并两个有序数组
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0, p2 = 0;
        int p = 0;
        vector<int> v = nums1;

        while((p1 < m) && (p2 < n)){
            nums1[p++] = (v[p1] < nums2[p2])? v[p1++] : nums2[p2++];
        }
        while(p1 < m){
            nums1[p++] = v[p1++];
        }
        while(p2 < n){
            nums1[p++] = nums2[p2++];
        }
    }
};