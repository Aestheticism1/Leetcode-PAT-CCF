#include<bits/stdc++.h>
using namespace std;
struct Station{//加油站结构体
    double dis;
    double price;
};
bool cmp(const Station&s1,const Station&s2){//比较函数
    return s1.dis!=s2.dis?s1.dis<s2.dis:s1.price<s2.price;
}
int main(){
    double Cmax,D,Davg;
    int N;
    scanf("%lf%lf%lf%d",&Cmax,&D,&Davg,&N);
    Station station[N+1];//定义N+1个车站
    for(int i=0;i<N;++i)//读取数据
        scanf("%lf%lf",&station[i].price,&station[i].dis);
    station[N].dis=D;//将最后一个加油站距离定为D，油价设为0，作为终点
    station[N].price=0;
    sort(station,station+N,cmp);//只对前N个车站按距离排序即可
    double farestDis=Cmax*Davg;//加满油最远能到达的距离
    double sumPrice=0.0,currentTank=0.0;//总花费，当前邮箱中的储油
    if(station[0].dis!=0.0){//如果在距离为0处没有加油站，不能出发，直接输出
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    int currentIndex=0;//当前加油站编号
    while(currentIndex<N){//如果没有到达终点，继续循环
        int minIndex=-1;//下一个应前往的加油站
        double minPrice=1e6*1.0;
        //寻找距离最近的油价低于currentIndex加油站minIndex，如果找不到，则在能到达的加油站中寻找油价最低的加油站minIndex
        for(int i=currentIndex+1;i<=N&&station[i].dis<=station[currentIndex].dis+farestDis;++i){
            if(minPrice>=station[i].price){
                minIndex=i;
                minPrice=station[i].price;
            }
            if(station[i].price<station[currentIndex].price)
                break;
        }
        if(minIndex==-1){ //如果到达不了任何加油站，输出最远能到达的距离
            double maxDis=station[currentIndex].dis+farestDis;
            printf("The maximum travel distance = %.2f",maxDis);
            return 0;
        }
        
        double tempTank=(station[minIndex].dis-station[currentIndex].dis)/Davg;//到达minIndex加油站需要使用的油量
        if(station[minIndex].price<station[currentIndex].price){//minIndex加油站油价低于当前加油站
            sumPrice+=station[currentIndex].price*(tempTank-currentTank);//只需加到能到达minIndex的油
            currentTank=0;//到达minIndex加油站油量为0
        }else{//minIndex加油站油价不低于当前加油站
            sumPrice+=station[currentIndex].price*(Cmax-currentTank);//在当前加油站加满油
            currentTank=Cmax-tempTank;//到达minIndex加油站油量为Cmax-tempTank
        }
        currentIndex=minIndex;//前往minIndex加油站
    }
    printf("%.2f",sumPrice);
    return 0;
}