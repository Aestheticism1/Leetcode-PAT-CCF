// 判断一个数组是不是某二叉搜索树的后序遍历序列

// 递归
// 后序遍历性质：[左子树，右子树，根节点]
// 二叉搜索树性质：左子树都<根节点值，右子树都>根节点值
// 思路：找到[l, r)第一个大于根节点的点i，判断[i, r)（右子树）是否都大于根节点，是则递归左右子树，否则返回false
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.empty()) return true;
        return helper(postorder, 0, postorder.size() - 1);
    }

    bool helper(vector<int>& post, int l, int r){
        if(l >= r) return true;
        int i = l;
        while(i < r && post[i] < post[r]) i++;
        int j = i;
        while(j < r && post[j] > post[r]) j++;
        return j == r && helper(post, l, i-1) && helper(post, i, r-1);
    }
};

// 单调栈
// 把序列倒过来有两个性质，详见lc
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.empty()) return true;
        stack<int> s;
        int parent = INT_MAX;
        for(int i = postorder.size() - 1; i >= 0; i--){
            int cur = postorder[i];
            while(!s.empty() && s.top() > cur){
                parent = s.top();
                s.pop();
            }
            if(cur > parent)
                return false;
            s.push(cur);
        }

        return true;
    }
};