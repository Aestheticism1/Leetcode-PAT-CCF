#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

const int L = 35;

struct TreeNode{
    TreeNode *left, *right;
    int val;
    TreeNode(int v): val(v), left(NULL), right(NULL){}
};
int n;
vector<int> inorder(L), postorder(L);
unordered_map<int, int> inorder_idx;
int post_index;

TreeNode* buildTree(int left, int right){
    if(left > right){
        return NULL;
    }
    int post = postorder[post_index];
    int index = inorder_idx[post];
    post_index--;
    TreeNode* root = new TreeNode(post);
    root->right = buildTree(index+1, right);
    root->left = buildTree(left, index-1);
    return root;
}

void level_order(TreeNode* root){
    queue<TreeNode*> q;
    int count = 0;
    q.push(root);
    while(!q.empty()){
        TreeNode* t = q.front();
        q.pop();
        if(++count != n)
            cout << t->val << " ";
        else
            cout << t->val;
        if(t->left != NULL)
            q.push(t->left);
        if(t->right != NULL)
            q.push(t->right);
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> postorder[i];
    
    for(int i = 0; i < n; ++i)
        cin >> inorder[i];
    
    for(int i = 0; i < n; ++i)
        inorder_idx[inorder[i]] = i;
    
    post_index = n - 1;
    TreeNode* root = buildTree(0, n-1);
    level_order(root);
    return 0;
}