#include <iostream>
#include <vector>

using namespace std;

struct Road{
    int end, dis, cos;
    Road(int e, int d, int c): end(e), dis(d), cos(c){}
};
const int L = 505;
int N, M, S, D;
vector<vector<Road> > graph(L);
vector<int> father(L);
vector<int> path; 
int dist[L];
bool mark[L];
int cost[L];

void dijistra(){
    while(!mark[D]){
        int min = INT_MAX, u;
        for(int i = 0; i < N; i++){
            if(!mark[i] && dist[i] < min){
                min = dist[i];
                u = i;
            }
        }
        mark[u] = true;
        for(auto v: graph[u]){\
            if(!mark[v.end]){
                if(dist[v.end] > dist[u] + v.dis){
                    dist[v.end] = dist[u] + v.dis;
                    cost[v.end] = cost[u] + v.cos;
                    father[v.end] = u;
                }else if(dist[v.end] == dist[u] + v.dis && cost[v.end] > cost[u] + v.cos){
                    cost[v.end] = cost[u] + v.cos;
                    father[v.end] = u;
                }
            }
        }
    }
}

int main()
{
    cin >> N >> M >> S >> D;
    for(int i = 0; i < M; ++i){
        int a, b, dis, cos;
        cin >> a >> b >> dis >> cos;
        graph[a].push_back(Road(b, dis, cos));
        graph[b].push_back(Road(a, dis, cos));
    }
    fill(dist, dist + L, INT_MAX);
    fill(cost, cost + L, 0);
    cost[S] = 0;
    dist[S] = 0;
    dijistra();
    int i = D;
    while(i != S){
        path.push_back(i);
        i = father[i];
    }
    path.push_back(S);
    for(int j = path.size()-1; j >= 0; j--)
        cout << path[j] << " ";
    cout << dist[D] << " " << cost[D];
    return 0;
}