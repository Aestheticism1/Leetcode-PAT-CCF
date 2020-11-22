#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
const int MAXV=(int)(1e5+5);
int N,product[MAXV];
double R,price[MAXV];
vector<int>graph[MAXV];
void DFS(int v){//深度优先遍历
    for(int i:graph[v]){
        price[i]=price[v]*(1+R/100);
        DFS(i);
    }
}
int main(){
    scanf("%d%lf%lf",&N,&price[0],&R);
    for(int i=0;i<N;++i){
        int m,a;
        scanf("%d",&m);
        if(m==0)
            scanf("%d",&product[i]);
        while(m--){
            scanf("%d",&a);
            graph[i].push_back(a);
        }
    }
    DFS(0);
    printf("%.1f",inner_product(price,price+N,product,0.0));
    return 0;
}