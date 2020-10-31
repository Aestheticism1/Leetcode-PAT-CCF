#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int L = 105;

int N, M;
vector<vector<int> > nodes(L);
int level[L];
int res[L];

int bfs(){
    queue<int> q;
    q.push(1);
    level[1] = 1;
    int depth = 1;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        if(nodes[a].size() == 0){
            res[level[a]]++;
        }
        
        for(auto x: nodes[a]){
            level[x] = level[a] + 1;
            depth = max(depth, level[x]);
            q.push(x);
        }
    }
    return depth;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    while(M--){
        int id, k, idk;
        cin >> id >> k;
        while(k--){
            cin >> idk;
            nodes[id].push_back(idk);
        }
    }

    int depth = bfs();
    for(int i = 1; i < depth; i++){
        cout << res[i] << " ";
    }
    cout << res[depth];

    return 0;
}