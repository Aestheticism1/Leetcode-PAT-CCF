#include <iostream>

using namespace std;

const int MAXV = 110;
const int MAXE = 10010;

struct edge{
    int u, v;
    int cost;
}E[MAXE];

int father[MAXV];
int findFather(int x){
    int a = x;
    while(x != father[x]){
        x = father[x];
    }
    while(a != father[a]){
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

// 克鲁斯卡尔算法，适合稀疏图
// 边贪心 + 并查集
int kruskal(int n, int m){
    for(int i = 0; i < n; i++)
        father[i] = i;
    sort(E, E+m, [](edge &e1, edge &e2){
        return e1.cost < e2.cost;
    });
    int ans = 0, cnt = 0;
    for(int i = 0; i < m; i++){
        int fu = findFather(E[i].u);
        int fv = findFather(E[i].v);
        if(fu != fv){
            father[fu] = fv;
            ans += E[i].cost;
            if(++cnt == n - 1)
                break;
        }
    }
    if(cnt != n - 1)
        return -1;
    return ans;
} 

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
        scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].cost);
    int ans = kruskal(n, m);
    printf("%d\n", ans);
    return 0;
}