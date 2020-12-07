#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int N,num=0,first=-1;//num存储最长连续因子个数、first存储连续因子的第一个数
    scanf("%d",&N);
    for(int i=2;i<=(int)sqrt(N*1.0);++i)//逐个枚举2~根号N的所有数
        if(N%i==0){//N能被i整除
            int n=0;//表示以i为首因子的连续因子个数
            for(int j=i;N%j==0;j*=i+n)//求出以i为首因子的连续因子个数
                ++n;
            if(n>num){//如果i>num，更新相关信息
                first=i;
                num=n;
            }
        }
    if(num==0)//num为0，表示在2~根号N中没有因子
        printf("1\n%d",N);//那么N为质数，输出1和它自己
    else{//否则输出num和对应的连续因子
        printf("%d\n",num);
        for(int i=0;i<num;++i)
            printf("%s%d",i>0?"*":"",first+i);
    }
    return 0;
}