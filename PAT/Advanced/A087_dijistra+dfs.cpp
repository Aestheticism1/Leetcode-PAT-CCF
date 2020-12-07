#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
const int L = 205;
int graph[L][L];
int N, K;
unordered_map<int, string> itn;
unordered_map<string, int> nti;
int happiness[L];
int dist[L];
bool mark[L];
vector<vector<int> > father(L);
vector<int> curr, res;
int maxH = INT_MIN;
int maxAH = INT_MIN;
int cnt = 0;
void disjistra(){
    while(!mark[nti["ROM"]]){
        int u, min = INT_MAX;
        for(int i = 0; i < N; ++i){
            if(!mark[i] && dist[i] < min){
                min = dist[i];
                u = i;
            }
        }
        mark[u] = true;
        for(int v = 0; v < N; ++v){
            if(!mark[v] && graph[u][v] != 0){
                if(dist[v] > dist[u] + graph[u][v]){
                    dist[v] = dist[u] + graph[u][v];
                    father[v].clear();
                    father[v].push_back(u);
                }else if(dist[v] == dist[u] + graph[u][v])
                    father[v].push_back(u);
            }
        }
    }
}
void dfs(int r){
    if(r == 0){
        cnt++;
        curr.push_back(r);
        int sum = 0;
        for(int i = 0; i < curr.size()-1; ++i){
            sum += happiness[curr[i]];
        }
        int avg = sum / (curr.size()-1);
        if(sum > maxH){
            maxH = sum;
            maxAH = avg;
            res = curr;
        }else if(sum == maxH && avg > maxAH){
            maxAH = avg;
            res = curr;
        }
        curr.pop_back();
        return;
    }
    curr.push_back(r);
    for(auto x: father[r]){
        dfs(x);
    }
    curr.pop_back();
}
int main()
{
    cin >> N >> K;
    string first;
    cin >> first;
    itn[0] = first;
    nti[first] = 0;
    happiness[0] = 0;
    for(int i = 1; i < N; ++i){
        string s;
        int h;
        cin >> s >> h;
        itn[i] = s;
        nti[s] = i;
        happiness[i] = h;
    }
    for(int i = 0; i < K; ++i){
        string a, b;
        int c;
        cin >> a >> b >> c;
        graph[nti[a]][nti[b]] = graph[nti[b]][nti[a]] = c;
    }
    fill(dist, dist + L, INT_MAX);
    dist[0] = 0;
    disjistra();
    dfs(nti["ROM"]);
    cout << cnt << " " << dist[nti["ROM"]] << " " << maxH << " " << maxAH << endl;
    for(int i = res.size()-1; i >= 0; i--){
        cout << itn[res[i]];
        if(i != 0)
            cout << "->"; 
    }
    return 0;
}