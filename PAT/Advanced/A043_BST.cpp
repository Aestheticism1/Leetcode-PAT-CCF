#include <iostream>
#include <vector>

using namespace std;

// BST前序遍历序列的性质：第25行的i-j==1
// 第28行直接得到后序遍历序列，可细品
vector<int>post,pre(1005);
bool mirror=false;//是否是镜像树
void postOrder(int left,int right){
    if(left>right)
        return;
    int i=left+1,j=right;//i指示右子树的第一个数在先根遍历序列中的索引，j指示左子树的最后一个数在先根遍历序列中的索引
    if(!mirror) {
        while(i<=right&&pre[left]>pre[i]) 
            ++i;
        while(j>left&&pre[left]<=pre[j]) 
            --j;
    }else{
        while(i<=right&&pre[left]<=pre[i]) 
            ++i;
        while(j>left&&pre[left]>pre[j]) 
            --j;
    }
    if(i-j!=1) return ;//i-j!=1，说明不能构成二叉查找树或镜像树，提前返回
    postOrder(left+1,i-1);//处理左子树
    postOrder(i,right);//处理右子树
    post.push_back(pre[left]);//将根节点加入后根遍历序列中
}
int better(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;++i)
        scanf("%d",&pre[i]);
    if(N>2&&pre[1]>pre[0])//判断是否是镜像树
        mirror=true;
    postOrder(0,N-1);//得出后根遍历序列
    if(post.size()==N){//得出的后根遍历序列中元素个数与给定的元素总数相等，说明能构成二叉查找树或镜像树
        printf("YES\n");
        for(int i=0;i<post.size();++i)
            printf("%s%d",i>0?" ":"",post[i]);
    }else//得出的后根遍历序列中元素个数与给定的元素总数相等，说明不能构成二叉查找树或镜像树
        printf("NO");
    return 0;
}

// mine
struct TreeNode{
    TreeNode *left, *right;
    int val;
    TreeNode(int v, TreeNode *left=NULL, TreeNode *right=NULL): val(v), left(left), right(right){}
};

void BuildTree(int val, TreeNode *root){
    if(val < root->val){
        if(root->left == NULL){
            TreeNode *node = new TreeNode(val);
            root->left = node;
            return;
        }else{
            BuildTree(val, root->left);
        }
    }else{
        if(root->right == NULL){
            TreeNode *node = new TreeNode(val);
            root->right = node;
            return;
        }else{
            BuildTree(val, root->right);
        }
    }
    return;
}

int k, cnt;
vector<int> origin;
void PreOrder(TreeNode *root){
    if(root == NULL){
        return;
    }
    if(root->val == origin[k++])
        cnt++;
    PreOrder(root->left);
    PreOrder(root->right);
}

vector<int> res;
void PostOrder(TreeNode *root){
    if(root == NULL){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    res.push_back(root->val);
}

void reverse(TreeNode *root){
    if(root->left == NULL && root->right == NULL)
        return;
    if(root->left != NULL)
        reverse(root->left);
    if(root->right != NULL)
        reverse(root->right);
    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    return;
}

int main()
{
    int N;
    cin >> N;
    if(N == 0){
        cout << "NO";
        return 0;
    }
    int tmp;
    cin >> tmp;
    origin.push_back(tmp);
    TreeNode *root = new TreeNode(tmp);
    N--;
    while (N--){
        cin >> tmp;
        origin.push_back(tmp);
        BuildTree(tmp, root);
    }

    k = 0, cnt = 0;
    PreOrder(root);
    if(cnt == origin.size()){
        cout << "YES" << endl;
        PostOrder(root);
        for(int i = 0; i < res.size(); i++){
            if(i != res.size()-1)
                cout << res[i] << " ";
            else
                cout << res[i];
        }
        return 0;
    }
    k = 0, cnt = 0;
    res.clear();
    reverse(root);
    PreOrder(root);
    if(cnt != origin.size())
        cout << "NO";
    else{
        cout << "YES" << endl;
        PostOrder(root);
        for(int i = 0; i < res.size(); i++){
            if(i != res.size()-1)
                cout << res[i] << " ";
            else
                cout << res[i];
        }
    }
    return 0;
}