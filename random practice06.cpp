//leetcode 977. 有序数组的平方
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> v;
        int p1 = 0, p2 = A.size() - 1;
        while(p1 <= p2){
            if(A[p1] * A[p1] > A[p2] * A[p2]){
                v.push_back(A[p1] * A[p1]);
                ++p1;
            } else {
                v.push_back(A[p2] * A[p2]);
                --p2;
            }
        }
        reverse(v.begin(), v.end());
        return v;
    }
};

//leetcode 917. 仅仅反转字母
class Solution {
public:
    string reverseOnlyLetters(string S) {
        if(S.empty()){
            return S;
        }

        int left = 0;
        int right = S.size() - 1;

        while(left < right){
            if(!(S[left] >= 'A' && S[left] <= 'Z' || S[left] >= 'a' && S[left] <= 'z')){
                ++left;
                continue;
            }
            if(!(S[right] >= 'A' && S[right] <= 'Z' || S[right] >= 'a' && S[right] <= 'z')){
                --right;
                continue;
            }
            if((S[left] >= 'A' && S[left] <= 'Z' || S[left] >= 'a' && S[left] <= 'z')
            && (S[right] >= 'A' && S[right] <= 'Z' || S[right] >= 'a' && S[right] <= 'z')){
                swap(S[left], S[right]);
                ++left;
                --right;
            } 
        }
        return S;
    }
};