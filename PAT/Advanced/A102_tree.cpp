#include<bits/stdc++.h>
using namespace std;
struct Node{//结点类，没有数据域
    int left=-1,right=-1;
};
Node tree[10];
void inOrder(int root,bool&space){//中根遍历，space指示输出数字之前是否需要输出空格
    if(root==-1)//root==-1,直接返回
        return;
    inOrder(tree[root].left,space);//递归遍历左子树
    printf("%s%d",space?" ":"",root);//输出
    space=true;//已经输出过，以后都需要输出空格，置false为true
    inOrder(tree[root].right,space);//递归遍历右子树
}
void levelOrder(int root){//层次遍历
    queue<int>q;
    q.push(root);
    while(!q.empty()){
        int t=q.front();
        q.pop();
        printf("%s%d",t==root?"":" ",t);//不是根节点的输出前都需输出一个空格
        if(tree[t].left!=-1)
            q.push(tree[t].left);
        if(tree[t].right!=-1)
            q.push(tree[t].right);
    }
}
int main(){
    int N;
    scanf("%d",&N);
    bool child[N]={false};
    for(int i=0;i<N;++i){
        char a,b;
        scanf("\n%c %c",&a,&b);
        if(a!='-'){
            tree[i].right=a-'0';
            child[a-'0']=true;
        }
        if(b!='-'){
            tree[i].left=b-'0';
            child[b-'0']=true;
        }
    }
    int root=find(child,child+N,false)-child;//仍为false的下标为根节点标号
    levelOrder(root);
    printf("\n");
    bool space=false;
    inOrder(root,space);
    return 0;
}