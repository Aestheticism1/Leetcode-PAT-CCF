#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,M,L,a;
    scanf("%d%d",&N,&M);
    int order[N+1]={0};
    for(int i=1;i<=M;++i){//给order数组赋值
        scanf("%d",&a);
        order[a]=i;
    }
    scanf("%d",&L);
    int A[L],maxLen=0,dp[L]={0};
    for(int i=0;i<L;++i)
        scanf("%d",&A[i]);
    for(int i=0;i<L;++i){//求解dp数组
        if(order[A[i]]>0){//是喜欢的颜色
            int MAX=0;
            for(int j=0;j<i;++j)//找出0~i-1之间满足order[i]>=order[j]的最大的dp值
                if(order[A[i]]>=order[A[j]])
                    MAX=max(dp[j],MAX);
            dp[i]=max(MAX+1,1);//更新dp数组值
            maxLen=max(maxLen,dp[i]);//更新最大长度
        }
    }
    printf("%d",maxLen);
    return 0;
}