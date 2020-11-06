#include <iostream>
#include <vector>
using namespace std;

const int L = 1e4 + 5;
vector<vector<int>> graph(L);
bool mark[L];
int level[L];
int max_level[L];

void dfs(int v, int root){
    mark[v] = true;
    for(auto x: graph[v]){
        if(!mark[x]){
            //子结点的深度+1
            level[x] = level[v] + 1;
            //更新以root为根结点的最大深度
            max_level[root] = max(max_level[root], level[x]);
            dfs(x, root);
        }
    }
}

int main()
{
    int N;
    cin >> N;
    for(int i = 1; i < N; ++i){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //先用dfs获取连通分量数量，同时得到了以1为根结点的最大深度
    int num = 0;
    for(int i = 1; i <= N; ++i){
        if(!mark[i]){
            ++num;
            dfs(i, i);
        }
    }

    if(num > 1)
        cout << "Error: " << num << " components" << endl;
    else{
        //以1为根结点的最大深度在上面已经得到，获取以2～N为根结点的最大深度
        for(int i = 2; i <= N; ++i){
            fill(level, level + L, 0);
            fill(mark, mark + L, false);
            dfs(i, i);
        }
        vector<int> res;
        int deepest = 0;
        for(int i = 1; i <= N; ++i){
            if(max_level[i] > deepest){
                deepest = max_level[i];
                res.clear();
                res.push_back(i);
            }else if(max_level[i] == deepest){
                res.push_back(i);
            }
        }
        sort(res.begin(), res.end());
        for(auto x: res){
            cout << x << endl;
        }
    }
    return 0;
}