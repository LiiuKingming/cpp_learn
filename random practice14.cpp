//leetcode 815. 公交线路
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T) return 0;
        int N = routes.size();
        map<int, set<int> > m; // 存储车站能通到哪些路线
        for (int i = 0; i < N; ++i) {
            for (auto j : routes[i]) {
                m[j].insert(i);
            }
        }
        vector<bool> visited(N, false); // 哪些路线被遍历过了
        queue<int> q; // 存储已经遍历过的路线
        for (auto x : m[S]) {
            q.push(x);
            visited[x] = true;
        }
        int step = 0;
        while (!q.empty()) {
            ++step;
            int s = q.size();
            for (int i = 0; i < s; ++i) {
                int t = q.front();
                q.pop();
                for (auto j : routes[t]) {
                    if (j == T) return step;
                    for (auto x : m[j]) {
                        if (!visited[x]) {
                            q.push(x);
                            visited[x] = true;
                        }
                    }
                }
            }
        }
        return -1;
    }
};

//leetcode 199. 二叉树的右视图
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 1);
        return ans;
    }
    
    void dfs(TreeNode* root, int i){
        if (root == NULL) return;
        if (ans.size() < i) ans.push_back(root->val);
        dfs(root->right, i+1);
        dfs(root->left, i+1);
    }
};