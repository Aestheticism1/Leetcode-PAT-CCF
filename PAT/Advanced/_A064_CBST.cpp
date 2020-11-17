#include<iostream>
using namespace std;
int N,position=0,A[1024],tree[1024];
void inorder(int root){
    if(root>N)
        return;
    inorder(2*root);//先遍历左子树
    tree[root]=A[position++];//填充根节点
    inorder(2*root+1);//遍历右子树
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;++i)
        scanf("%d",&A[i]);
    sort(A,A+N);
    inorder(1);
    for(int i=1;i<=N;++i)//输出
        printf("%s%d",i>1?" ":"",tree[i]);
    return 0;
}