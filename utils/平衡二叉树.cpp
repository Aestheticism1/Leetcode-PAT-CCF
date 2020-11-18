#include <iostream>

using namespace std;

struct AVLTreeNode{
    int val, height;
    AVLTreeNode *left, *right;
    AVLTreeNode(int v, AVLTreeNode *l=nullptr, AVLTreeNode *r=nullptr): val(v), height(0), left(l), right(r){}
};

int getHeight(AVLTreeNode *root){
    return root == nullptr ? 0 : root->height;
}

AVLTreeNode* LLRotation(AVLTreeNode* &k2){
    AVLTreeNode* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(k2->left->height, k2->right->height) + 1;
    k1->height = max(k1->left->height, k2->height) + 1;
    return k1;
}

AVLTreeNode* RRRotation(AVLTreeNode* &k1){
    AVLTreeNode* k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max(k1->left->height, k1->right->height) + 1;
    k2->height = max(k1->height, k2->right->height) + 1;
    return k2;
}

AVLTreeNode* LRRotation(AVLTreeNode* &k){
    k->left = RRRotation(k->left);
    return LLRotation(k);
}

AVLTreeNode* RLRotation(AVLTreeNode* &k){
    k->right = LLRotation(k->right);
    return RRRotation(k);
}

AVLTreeNode* insert(AVLTreeNode* &root, int data){
    if(root == nullptr){
        return new AVLTreeNode(data);
    }else if(data < root->val){
        root->left = insert(root->left, data);
        if(getHeight(root->left) - getHeight(root->right) == 2){
            if(data < root->left->val)
                root = LLRotation(root);
            else
                root = LRRotation(root);
        }
    }else if(data > root->val){
        root->right = insert(root->right, data);
        if(getHeight(root->right) - getHeight(root->left) == 2){
            if(data > root->right->val)
                root = RRRotation(root);
            else 
                root = RLRotation(root);
        }
    }else{
        cout << "fuck" << endl;
    }
    root->height = max(root->left->height, root->right->height) + 1;
    return root;
}

int main()
{
    
    return 0;
}