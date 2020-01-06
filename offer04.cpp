/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size() == 0 || vin.size() == 0)
            return nullptr;
        return ConstructBinaryTree(pre, vin, 0, pre.size() - 1, 0, vin.size() - 1);
    }
    TreeNode *ConstructBinaryTree(vector<int> &pre, vector<int> &vin, int leftpre, int rightpre, int leftin, int rightin){
        if(leftpre > rightpre || leftin > rightin)
            return nullptr;
        //前序遍历的第一个数字是根节点的值
        int rootVal = pre[leftpre];
        //构造新的节点,并初始化(val left right)
        TreeNode *root = new TreeNode(rootVal);

        //中序遍历序列中找到根节点的值
        int rootin = leftin;
        while(rootin <= rightin && rootVal != vin[rootin])
            ++rootin;
        
        if(rootin == rightin && rootVal != vin[rootin])
            return nullptr;

        int left = rootin - leftin;//左子树长度
        //构建左子树
        root->left = ConstructBinaryTree(pre, vin, leftpre + 1, leftpre + left, leftin, rootin - 1);

        //构建右子树
        root->right = ConstructBinaryTree(pre, vin, leftpre + left + 1, rightpre, rootin + 1, rightin);

        return root;
    }
};