#include <iostream>
#include <vector>

using namespace std;

// 根据层序数组建树
// 例：{1, 2, 3, 4, 5, -1, 6, -1, -1, 7, 8}

struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int v): val(v), left(NULL), right(NULL){}
};

TreeNode* construct_tree_from_vector(const vector<int> a, int i){
    if(i >= a.size() || a[i] == -1)
        return NULL;
    TreeNode* root = new TreeNode(a[i]);
    root->left = construct_tree_from_vector(a, i*2+1);
    root->right = construct_tree_from_vector(a, i*2+2);
    return root;
}

void preorder(TreeNode* root){
    if(root == NULL)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    vector<int> a{1, 2, 3, 4, 5, -1, 6, -1, -1, 7, 8};
    TreeNode* root = construct_tree_from_vector(a, 0);
    preorder(root);
    return 0;
}