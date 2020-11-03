#include <iostream>
#include <vector>

using namespace std;

const int L = 1005;

int n, m, k;
vector<vector<int>> graph(L);
bool mark[L];

void dfs(int i, const int x){
    mark[i] = true;
    for(auto v: graph[i]){
        if(!mark[v] && v != x){
            dfs(v, x);
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    while(m--){
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    while(k--){
        int x;
        cin >> x;
        int cnt = 0;
        fill(mark, mark + L, false);
        for(int i = 1; i <= n; ++i){
            if(i == x)
                continue;
            if(!mark[i]){
                dfs(i, x);
                cnt++;
            }
        }
        cout << cnt-1 << endl;
    }
    return 0;
}