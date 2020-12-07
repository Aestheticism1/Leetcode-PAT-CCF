#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    scanf("%d",&N);
    int a[N],leftMax[N]={0},rightMin[N]={0};//定义存储序列的数组，存储相应位置左侧最大值的数组，存储相应位置右侧最小值的数组
    rightMin[N-1]=INT_MAX;
    for(int i=0;i<N;++i)
        scanf("%d",&a[i]);
    for(int i=1;i<N;++i)//遍历查找相应位置左侧最大值
        leftMax[i]=max(leftMax[i-1],a[i-1]);
    for(int i=N-2;i>=0;--i)//遍历查找相应位置右侧最小值
        rightMin[i]=min(rightMin[i+1],a[i+1]);
    vector<int>result;//存储主元的vector
    for(int i=0;i<N;++i)//查找主元
        if(a[i]>leftMax[i]&&a[i]<rightMin[i])
            result.push_back(a[i]);
    printf("%d\n",result.size());
    //下面的排序语句可有可无
    //    sort(a,a+N,[](const int n1,const int n2){
    //        return n1>n2;
    //    });
    if(result.size()==0)//如果没有这样的主元，输出一个空行
        printf("\n");
    else
        for(int i=0;i<result.size();++i){
            if(i>0)
                printf(" ");
            printf("%d",result[i]);
        }
    return 0;
}