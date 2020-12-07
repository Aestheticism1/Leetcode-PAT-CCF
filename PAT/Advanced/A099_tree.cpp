#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int v, TreeNode *l=nullptr, TreeNode *r=nullptr): val(v), left(l), right(r){}
};
int A[105];
int ind = 0, cnt = 0;
int N;
void inorder(TreeNode *root){
    if(root == nullptr)
        return;
    inorder(root->left);
    root->val = A[ind++];
    inorder(root->right);
}
void levelorder(TreeNode *root){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode *r = q.front();
        cout << r->val;
        if(++cnt != N)
            cout << " ";
        q.pop();
        if(r->left != nullptr)
            q.push(r->left);
        if(r->right != nullptr)
            q.push(r->right);
    }
}
int main() 
{
    cin >> N;
    unordered_map<int, TreeNode*> hash;
    for(int i = 0; i < N; ++i){
        hash[i] = new TreeNode(i);
    }
    hash[-1] = nullptr;
    for(int i = 0; i < N; ++i){
        int a, b;
        cin >> a >> b;
        hash[i]->left = hash[a];
        hash[i]->right = hash[b];
    }
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    sort(A, A+N);
    inorder(hash[0]);
    levelorder(hash[0]);
    return 0;
}