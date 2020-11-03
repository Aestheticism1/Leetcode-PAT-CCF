#include <iostream>
#include <vector>

using namespace std;

const int L = 505;

struct Road{
    int end;
    int length;
    Road(int e, int l): end(e), length(l){}
};

int cmax, n, sp, m;
int weight[L];
vector<vector<Road>> graph(L);
vector<vector<int> > father(L);    //存储最短路径中每个节点的父节点
int dist[L];
bool mark[L];
vector<int> currPath, path;     //currentPath存储当前最短路径，path存储最优路径
int minSend=INT_MAX, minCollect=INT_MAX;    //minSend最少派出，minCollect最少带回

// 先用dijistra找最短路径
void dijistra(){
    while(!mark[sp]){
        int min = INT_MAX;
        int u;
        for(int i = 0; i <= n; i++){
            if(!mark[i] && dist[i] < min){
                min = dist[i];
                u = i;
            }
        }
        mark[u] = true;
        for(auto x: graph[u]){
            if(!mark[x.end]){
                if(dist[x.end] > dist[u] + x.length){
                    dist[x.end] = dist[u] + x.length;
                    father[x.end].clear();      //将已有父节点清空，再压入唯一父节点
                    father[x.end].push_back(u);
                }else if(dist[x.end] == dist[u] + x.length){
                    father[x.end].push_back(u); //添加一个父节点
                }
            }
        }
    }
}

// 再用dfs遍历最短路径
void dfs(int v){
    // 因为dijistra存储的是父节点，所以是从终点开始dfs到起点
    // 此时遍历到起点0说明已经获得了一条最短路径
    if(v == 0){
        int currSend = 0, currCollect = 0;
        for(int i = currPath.size()-1; i >= 0; i--){
            if(weight[currPath[i]] >= 0){   //如果当前结点的自行车数量高于Cmax/2
                currCollect += weight[currPath[i]];    //将高于Cmax/2的自行车数量携带上
            }else{
                if(currCollect >= abs(weight[currPath[i]])){    //从路上携带的自行车多于当前结点需要补充的自行车数量
                    currCollect += weight[currPath[i]];     
                }else{                                 //需要PBMC派出自行车
                    currSend -= currCollect + weight[currPath[i]];
                    currCollect = 0;
                }
            }
        }
        currPath.push_back(0);
        if(currSend < minSend){ // 派出的自行车数量越少越好，更新最优路径等信息
            path = currPath;
            minSend = currSend;
            minCollect = currCollect;
        }else if(currSend == minSend && currCollect < minCollect){ // 派出的自行车数量相等时，带回的自行车数量越少越好
            path = currPath;
            minCollect = currCollect;
        }
        currPath.pop_back();
        return ;
    }

    // 压入当前路径
    currPath.push_back(v);
    for(int i = 0; i < father[v].size(); i++)
        dfs(father[v][i]);
    // 弹出已走过的结点，从而去走其他没有走过的路径
    currPath.pop_back();
}

int main()
{
    cin >> cmax >> n >> sp >> m;
    int tmp;
    for(int i = 1; i <= n; ++i){
        cin >> tmp;
        weight[i] = tmp - cmax / 2;
    }
    while(m--){
        int si, sj, tij;
        cin >> si >> sj >> tij;
        graph[si].push_back(Road(sj, tij));
        graph[sj].push_back(Road(si, tij));
    }

    fill(dist, dist+L, INT_MAX);
    dist[0] = 0;
    dijistra();
    dfs(sp);

    cout << minSend << " ";
    for(int i = path.size()-1; i >= 1; --i)
        cout << path[i] << "->";
    cout << path[0];
    cout << " " << minCollect;
    return 0;
}