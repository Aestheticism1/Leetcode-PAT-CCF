# include<iostream>
using namespace std;
const int MAXSize=(int)(1e5);//题目表长最大为10的4次方，可以建立一个10的5次方以内的素数表
//埃氏筛法建立素数表
bool prime[MAXSize];
void findPrime(){
    prime[0]=prime[1]=true;
    for(int i=2;i<MAXSize;++i)
        if(!prime[i])
            for(int j=i+i;j<MAXSize;j+=i)
                prime[j]=true;
}
int main(){
    findPrime();//建立素数表
    int N,M,a;
    scanf("%d%d",&M,&N);
    while(prime[M])
        ++M;
    int table[M];//哈希表
    fill(table, table+M, 0);
    for(int j=0;j<N;++j){
        scanf("%d",&a);
        int k=a%M;
        for(int i=1;i<=M&&table[k]!=0;k=(a+i*i)%M,++i);//查找元素能够插入的位置
        if(table[k]==0){//该元素能插入
            table[k]=a;
            printf("%s%d",j>0?" ":"",k);
        }else//该元素不能插入
            printf("%s-",j>0?" ":"");
    }
    return 0;
}