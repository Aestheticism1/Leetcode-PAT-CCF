#include<bits/stdc++.h>
using namespace std;
struct Testee{//考生类
    long long id;
    int score,localNumber,rank[2]={1,1};//考场排名、总排名
};
vector<Testee>testee;//存储考生的vector
void setRank(int index,int _begin,int _end){//计算排名,index为0、1分别代表计算考场内排名、总排名
    sort(testee.begin()+_begin,testee.begin()+_end,[](const Testee&t1,const Testee&t2){//比较函数，先按成绩由大到小排序，成绩相同的按准考证号有小到大排序
        return (t1.score!=t2.score)?t1.score>t2.score:t1.id<t2.id;
    });//排序
    for(int j=_begin+1;j<testee.size();++j)//计算排名
        if(testee[j].score==testee[j-1].score)
            testee[j].rank[index]=testee[j-1].rank[index];
        else
            testee[j].rank[index]=j-_begin+1;
}
int main(){
    int N,K;
    scanf("%d",&N);
    for(int i=1;i<=N;++i){//i代表考场号，由1~N编号
        scanf("%d",&K);//读入整个考场人数
        int start=testee.size();//定义当前考生总数，并得到本考场考生在vector中开始存储的索引
        for(int j=0;j<K;++j){//读入考生信息
            Testee t;
            scanf("%lld%d",&t.id,&t.score);
            t.localNumber=i;
            testee.push_back(t);
        }
        setRank(0,start,start+K);
    }
    setRank(1,0,testee.size());
    printf("%d\n",testee.size());;
    for(int i=0;i<testee.size();++i)
        printf("%013lld %d %d %d\n",testee[i].id,testee[i].rank[1],testee[i].localNumber,testee[i].rank[0]);
    return 0;
}