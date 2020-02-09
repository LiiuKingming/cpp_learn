//leetcode 78.子集
class Solution {
    vector<vector<int>> ret;
    vector<int> v;
    void dfs(long long idx) {
        if(idx == v.size())
            return;
        int len = ret.size();
        for(int i = 0; i < len; i++) {
            auto tmp = ret[i];
            tmp.push_back(v[idx]);
            ret.push_back(tmp);
        }
        dfs(idx + 1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        v = nums;
        ret.push_back({});
        dfs(0);
        return ret;
    }
};