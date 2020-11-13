#include<iostream>
#include<vector>
using namespace std;
const int L = 1e5+5;
int data[L],Next[L];
bool cmp(int a,int b){//比较函数
    return data[a]<data[b];
}
int main(){
    int N,first;
    scanf("%d%d",&N,&first);
    if(first==-1){//为空链表时直接输出0 -1
        printf("0 -1\n");
        return 0;
    }
    for(int i=0;i<N;++i){//读取数据  
        int a;
        scanf("%d",&a);
        scanf("%d%d",&data[a],&Next[a]);
    }
    vector<int>listAddress;//储存链表结点地址 
    while(first!=-1){
        listAddress.push_back(first);
        first=Next[first];
    }
    sort(listAddress.begin(),listAddress.end(),cmp);//按data从小到大排序
    printf("%d %05d\n",listAddress.size(),listAddress.front());
    for(int i=0;i<listAddress.size()-1;++i)
        printf("%05d %d %05d\n",listAddress[i],data[listAddress[i]],listAddress[i+1]);
    printf("%05d %d -1",listAddress.back(),data[listAddress.back()]);
    return 0;
}