#include <iostream>
#include <vector>

using namespace std;

const int L = 505;

struct Road{
  int end;
  int length;
  Road(int e, int l): end(e), length(l){}  
};

int n, m, curr, dest;
int city[L];
int dis[L];
int path_num[L];
int team_num[L];
bool mark[L];
vector<vector<Road> > graph(L);

void dijistra(){
    while(!mark[dest]){
        int min = INT_MAX;
        int u;
        for(int j = 0; j < n; j++){
            if(!mark[j] && dis[j] < min){
                min = dis[j];
                u = j;
            }
        }
        mark[u] = true;
        for(Road r: graph[u]){
            if(!mark[r.end]){
                // 精髓，可细品
                if(dis[r.end] > dis[u] + r.length){
                    dis[r.end] = dis[u] + r.length;
                    path_num[r.end] = path_num[u];
                    team_num[r.end] = team_num[u] + city[r.end];
                }else if(dis[r.end] == dis[u] + r.length){
                    path_num[r.end] += path_num[u];
                    team_num[r.end] = max(team_num[r.end], team_num[u] + city[r.end]);
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m >> curr >> dest;

    for(int i = 0; i < n; ++i)
        cin >> city[i];
    
    int c1, c2, l;
    while(m--){
        cin >> c1 >> c2 >> l;
        graph[c1].push_back(Road(c2, l));    
        graph[c2].push_back(Road(c1, l));    
    }

    fill(dis, dis + n, INT_MAX);
    dis[curr] = 0;
    path_num[curr] = 1;
    team_num[curr] = city[curr];
    dijistra();
    cout << path_num[dest] << " " << team_num[dest];
    return 0;
}