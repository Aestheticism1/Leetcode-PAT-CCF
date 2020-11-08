#include<bits/stdc++.h>
using namespace std;
struct Player{
    int arriveTime=0,processTime=0;//到达时间、打乒乓球的时间
    bool vip=false;//是否是VIP运动员
};
struct Table{
    bool occupy=false,vip=false;//目前是否被占用、是否是VIP球台
    int serverPlayerNum=0;//一天内服务的运动员数量
};
Player player[10005];//运动员数组
Table table[105];//乒乓球台数组
struct PlayerTable{
    int tableNum,playerNum,time;//球台编号、运动员编号、时间
    PlayerTable(int table,int p,int t):tableNum(table),playerNum(p),time(t){}//构造函数
    bool operator <(const PlayerTable&p)const{//重载<运算符
        return this->time>p.time;
    }
};
priority_queue<PlayerTable>playerTable;//优先级队列
list<int>waitPlayer;//等待序列
const int closeTime=21*3600;//体育馆关闭时间
int N,M,K;
int searchTable(bool vip){//查找空闲的球台，如果运动员是vip，优先查找vip球台。查找到返回该球台的索引，否则返回-1
    if(vip)
        for(int i=1;i<=K;++i)
            if(!table[i].occupy&&table[i].vip)
                return i;
    for(int i=1;i<=K;++i)
        if(!table[i].occupy)
            return i;
    return -1;
}
void output(int t1,int t2){//输出到达时间t1，接受服务时间t2，两者之间的时间间隔（注意这里以分为单位，且需四舍五入）
    printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",t1/3600,t1/60%60,t1%60,t2/3600,t2/60%60,t2%60,(t2-t1+30)/60);
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;++i){//读取数据
        int h,m,s;
        player[i].arriveTime=closeTime;
        scanf("%d:%d:%d %d %d",&h,&m,&s,&player[i].processTime,&player[i].vip);
        player[i].arriveTime=(h*60+m)*60+s;
        player[i].processTime=min(player[i].processTime,120);
        player[i].processTime*=60;
        playerTable.push(PlayerTable(0,i,player[i].arriveTime));
    }
    scanf("%d%d",&K,&M);
    for(int i=0;i<M;++i){//判断vip球台
        int a;
        scanf("%d",&a);
        table[a].vip=true;
    }
    while(!playerTable.empty()){//队列不空继续循环
        PlayerTable p=playerTable.top();//获取队首元素
        playerTable.pop();//弹出队首元素
        if(p.time>=closeTime)//如果队首元素时间晚于关闭时间，跳出循环
            break;
        if(p.tableNum==0){//球台编号为0，表示需要分配球台
            int index=searchTable(player[p.playerNum].vip);//查找空闲球台
            if(index!=-1){//查找到更新相关信息
                table[index].occupy=true;//该球台被占用
                int endTime=p.time+player[p.playerNum].processTime;//获取该球台的空闲时间压入优先级队列
                playerTable.push(PlayerTable(index,p.playerNum,endTime));
                output(player[p.playerNum].arriveTime,p.time);//输出
                ++table[index].serverPlayerNum;//递增该球台服务人数
            }else//查找不到空闲球台归入等待序列
                waitPlayer.push_back(p.playerNum);
        }else{//球台编号不为0，表示该球台可以闲置
            if(waitPlayer.empty())//如果等待序列为空
                table[p.tableNum].occupy=false;//球台闲置
            else{//如果等待序列不空
                int temp;
                if(!table[p.tableNum].vip){//球台非VIP分配给等待序列队首元素
                    temp=waitPlayer.front();
                    waitPlayer.pop_front();
                }else{//球台是VIP
                    auto i=waitPlayer.begin();
                    while(i!=waitPlayer.end()&&!player[*i].vip)//查找等待序列中有无VIP运动员
                        ++i;
                    if(i==waitPlayer.end()){//没有分配给等待序列队首元素
                        temp=waitPlayer.front();
                        waitPlayer.pop_front();
                    }else{//有，分配给第一个VIP运动员
                        temp=*i;
                        waitPlayer.erase(i);
                    }
                }
                int endTime=p.time+player[temp].processTime;//更新相关信息
                playerTable.push(PlayerTable(p.tableNum,temp,endTime));
                output(player[temp].arriveTime,p.time);
                ++table[p.tableNum].serverPlayerNum;
            }
        }
    }
    for(int i=1;i<=K;++i)
        printf("%s%d",i>1?" ":"",table[i].serverPlayerNum);
    return 0;
}