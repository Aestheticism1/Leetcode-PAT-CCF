#include <iostream>

using namespace std;

struct AVLTreeNode{
    int val, height;
    AVLTreeNode *left, *right;
    AVLTreeNode(int v, AVLTreeNode *l=nullptr, AVLTreeNode *r=nullptr): val(v), height(0), left(l), right(r){}
};

// 获取高度（计算平衡因子）
int getHeight(AVLTreeNode *root){
    return root == nullptr ? 0 : root->height;
}

// 左左（左单旋转）
AVLTreeNode* LLRotation(AVLTreeNode* k2){
    AVLTreeNode* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(getHeight(k2->left), getHeight(k2->right)) + 1;    // k1、k2子树变了，更新高度
    k1->height = max(getHeight(k1->left), k2->height) + 1;
    return k1;
}

// 右右（右单旋转）
AVLTreeNode* RRRotation(AVLTreeNode* k1){
    AVLTreeNode* k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max(getHeight(k1->left), getHeight(k1->right)) + 1;    // k1、k2子树变了，更新高度
    k2->height = max(k1->height, getHeight(k2->right)) + 1;
    return k2;
}

// 左右（左双旋转）
AVLTreeNode* LRRotation(AVLTreeNode* k){
    k->left = RRRotation(k->left);
    return LLRotation(k);
}

// 右左（右双旋转）
AVLTreeNode* RLRotation(AVLTreeNode* k){
    k->right = LLRotation(k->right);
    return RRRotation(k);
}

// 将结点插入到AVL树中，并返回根节点
AVLTreeNode* Insert(AVLTreeNode* &root, int data){
    if(root == nullptr){
        root = new AVLTreeNode(data);
    }else if(data < root->val){
        root->left = Insert(root->left, data);  // 插入左子树
        if(getHeight(root->left) - getHeight(root->right) == 2){    // 插入结点后，平衡因子大于1，则需要调整
            if(data < root->left->val)
                root = LLRotation(root);
            else
                root = LRRotation(root);
        }
    }else if(data > root->val){
        root->right = Insert(root->right, data);    // 插入右子树
        if(getHeight(root->right) - getHeight(root->left) == 2){    // 插入结点后，平衡因子大于1，则需要调整
            if(data > root->right->val)
                root = RRRotation(root);
            else 
                root = RLRotation(root);
        }
    }else{
        cout << "fuck" << endl;
    }
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;  // 递归更新树高
    return root;
}

// 找到从root出发最大的结点
AVLTreeNode* findMax(AVLTreeNode* root){
    if(root == nullptr)
        return nullptr;
    if(root->right == nullptr)
        return root;
    return findMax(root->right);
}

// 找到从root出发最小的结点
AVLTreeNode* findMin(AVLTreeNode* root){
    if(root == nullptr)
        return nullptr;
    if(root->left == nullptr)
        return root;
    return findMin(root->left);
}

// 删除
bool Delete(AVLTreeNode* &root, int x){
    if(root == nullptr)
        return false;
    else if(root->val == x){
        // 左右子树都非空
        if(root->left != nullptr && root->right != nullptr){
            // 左子树高度大，删除左子树中值最大的结点，将其赋给根结点
            if(getHeight(root->left) > getHeight(root->right)){
                root->val = findMax(root->left)->val;
                Delete(root->left, root->val);
            }else{  // //右子树高度大，删除右子树中值最小的结点，将其赋给根结点
                root->val = findMin(root->right)->val;
                Delete(root->right, root->val);
            }
        }else{  // 左右子树至少有一个为空，直接用那个非空子树或NULL替换根结点
            AVLTreeNode *old = root;
            root = root->left != nullptr ? root->left : root->right;
            delete old;
        }
    }else if(x < root->val){
        Delete(root->left, x);     // 递归删除左子树结点
        if(getHeight(root->right) - getHeight(root->left) == 2){    // 不满足平衡条件，需要调整
            if(getHeight(root->right->left) > getHeight(root->right->right))
                root = RLRotation(root);
            else
                root = RRRotation(root);
        }else   // 满足平衡条件，更新高度
            root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    }else{
        Delete(root->right, x);    // 递归删除右子树结点
        if(getHeight(root->left) - getHeight(root->right) == 2){    // 不满足平衡条件，需要调整
            if(getHeight(root->left->right) > getHeight(root->left->left))
                root = LRRotation(root);
            else
                root = LLRotation(root);
        }else   // 满足平衡条件，更新高度
            root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    }
    return true;
}

// 查找
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