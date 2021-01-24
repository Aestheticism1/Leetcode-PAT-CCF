// 二叉树中和为某一值的路径
// dfs回溯

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
    void dfs(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& res){
        if(root == NULL)
            return ;
        sum -= root->val;
        path.push_back(root->val);
        if(sum == 0 && root->left == NULL && root->right == NULL){
            res.push_back(path);
        }
        dfs(root->left, sum, path, res);
        dfs(root->right, sum, path, res);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int>> res;
        dfs(root, sum, path, res);
        return res;
    }
};