#include<iostream>
#include<vector>
using namespace std;
int Data[100005],Next[100005];
int main(){
    int begin,N,K;
    scanf("%d%d%d",&begin,&N,&K);
    for(int i=0;i<N;++i){//读取数据
        int address;
        scanf("%d",&address);
        scanf("%d%d",&Data[address],&Next[address]);
    }
    vector<int>listAddress;//储存链表结点地址
    while(begin!=-1){
        listAddress.push_back(begin);
        begin=Next[begin];
    }
    for(int i=K;i<=listAddress.size();i+=K)//进行翻转
        reverse(listAddress.begin()+i-K,listAddress.begin()+i);
    for(int i=0;i<listAddress.size()-1;++i)//输出
        printf("%05d %d %05d\n",listAddress[i],Data[listAddress[i]],listAddress[i+1]);
    printf("%05d %d -1\n",listAddress.back(),Data[listAddress.back()]);
    return 0;
}