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

AVLTreeNode* LLRotation(AVLTreeNode* k2){
    AVLTreeNode* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(getHeight(k2->left), getHeight(k2->right)) + 1;
    k1->height = max(getHeight(k1->left), k2->height) + 1;
    return k1;
}

AVLTreeNode* RRRotation(AVLTreeNode* k1){
    AVLTreeNode* k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max(getHeight(k1->left), getHeight(k1->right)) + 1;
    k2->height = max(k1->height, getHeight(k2->right)) + 1;
    return k2;
}

AVLTreeNode* LRRotation(AVLTreeNode* k){
    k->left = RRRotation(k->left);
    return LLRotation(k);
}

AVLTreeNode* RLRotation(AVLTreeNode* k){
    k->right = LLRotation(k->right);
    return RRRotation(k);
}

AVLTreeNode* Insert(AVLTreeNode* &root, int data){
    if(root == nullptr){
        root = new AVLTreeNode(data);
    }else if(data < root->val){
        root->left = Insert(root->left, data);
        if(getHeight(root->left) - getHeight(root->right) == 2){
            if(data < root->left->val)
                root = LLRotation(root);
            else
                root = LRRotation(root);
        }
    }else if(data > root->val){
        root->right = Insert(root->right, data);
        if(getHeight(root->right) - getHeight(root->left) == 2){
            if(data > root->right->val)
                root = RRRotation(root);
            else 
                root = RLRotation(root);
        }
    }else{
        cout << "fuck" << endl;
    }
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    return root;
}

AVLTreeNode* findMax(AVLTreeNode* root){
    if(root == nullptr)
        return nullptr;
    if(root->right == nullptr)
        return root;
    return findMax(root->right);
}

AVLTreeNode* findMin(AVLTreeNode* root){
    if(root == nullptr)
        return nullptr;
    if(root->left == nullptr)
        return root;
    return findMin(root->left);
}

bool Delete(AVLTreeNode* &root, int x){
    if(root == nullptr)
        return false;
    else if(root->val == x){
        if(root->left != nullptr && root->right != nullptr){
            if(getHeight(root->left) > getHeight(root->right)){
                root->val = findMax(root->left)->val;
                Delete(root->left, root->val);
            }else{
                root->val = findMin(root->right)->val;
                Delete(root->right, root->val);
            }
        }else{
            AVLTreeNode *old = root;
            root = root->left != nullptr ? root->left : root->right;
            delete old;
        }
    }else if(x < root->val){
        Delete(root->left, x);
        if(getHeight(root->right) - getHeight(root->left) == 2){
            if(getHeight(root->right->left) > getHeight(root->right->right))
                root = RLRotation(root);
            else
                root = RRRotation(root);
        }else
            root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    }else{
        Delete(root->right, x);
        if(getHeight(root->left) - getHeight(root->right) == 2){
            if(getHeight(root->left->right) > getHeight(root->left->left))
                root = LRRotation(root);
            else
                root = LLRotation(root);
        }else
            root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    }
    return true;
}

AVLTreeNode* findNode(AVLTreeNode* root, int x){
    if(root == nullptr || root->val == x)
        return root;
    else if(x < root->val)
        return findNode(root->left, x);
    else
        return findNode(root->right, x);
}

int main()
{
    int N, tmp;
    cin >> N;
    AVLTreeNode *root = nullptr;
    while(N--){
        cin >> tmp;
        root = Insert(root, tmp);
    }
    cout << root->val;
    return 0;
}