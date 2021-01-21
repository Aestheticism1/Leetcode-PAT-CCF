// 二叉树A和B，判断B是不是A的子结构
// 双重递归
// 先序遍历 + 判断子结构

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
    bool helper(TreeNode* A, TreeNode* B){
        // B遍历完了，返回true
        if(B == NULL)
            return true;
        // B还有，但A遍历完了，返回false
        if(A == NULL)
            return false;
        // 不相等，返回false
        if(A->val != B->val)
            return false;
        return helper(A->left, B->left) && helper(A->right, B->right);
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A == NULL || B == NULL)
            return false;
        bool res = false;
        // 在A中匹配到了与B根节点值一样的节点
        if(A->val == B->val)
            res = helper(A, B);
        // 如果匹配不到，A往左
        res |= isSubStructure(A->left, B);
        // 如果还是匹配不到，A往右
        res |= isSubStructure(A->right, B);
        return res;
    }
};