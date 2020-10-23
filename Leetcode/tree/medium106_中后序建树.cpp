#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int post_index;
unordered_map<int, int> inorder_idx;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

TreeNode* helper(int in_left, int in_right, vector<int>& inorder, vector<int>& postorder){
    if(in_left > in_right)
        return nullptr;
    
    // 一次只对后序遍历的一个结点建树
    int root_val = postorder[post_index];
    post_index--;

    TreeNode* t = new TreeNode(root_val);
    // 找到本次处理的后序结点在中序中的位置
    int pos = inorder_idx[root_val];

    // 建立本次处理的后序结点的左右子树
    t->right = helper(pos+1, in_right, inorder, postorder);
    t->left = helper(in_left, pos-1, inorder, postorder);
    return t;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
    post_index = postorder.size() - 1;
    int i = 0;
    // 建立（元素，下标）键值对的哈希表，方便查询后序结点在中序中的位置
    for(auto& val : inorder){
        inorder_idx[val] = i++;
    }
    return helper(0, inorder.size() - 1, inorder, postorder);
}

void inorder(TreeNode* root){
    if(root == nullptr)
        return ;
    cout << root->val << " ";
    inorder(root->left);
    inorder(root->right);
}

int main()
{
    int N;
    cin >> N;
    vector<int> in, post;
    int tmp;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        in.push_back(tmp);
    }
    for(int i = 0; i < N; i++){
        cin >> tmp;
        post.push_back(tmp);
    }
        
    TreeNode* root = buildTree(in, post);
    inorder(root);
    return 0;
}