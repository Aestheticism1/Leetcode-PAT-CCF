#include <iostream>
#include <vector>

using namespace std;

const int L = 105;
int N, M, S;
int weight[L];
vector<int> nodes[L];
vector<int> father(L, -1);
vector<vector<int> > res;

void dfs(int root, int sum){
    sum += weight[root];
    if(sum > S || (sum == S && !nodes[root].empty()))
        return;
    if(sum == S){
        vector<int> tmp;
        while(root != -1){
            tmp.push_back(root);
            root = father[root];
        }
        res.push_back(tmp);
        return;
    }
    for(auto x: nodes[root]){
        father[x] = root;
        dfs(x, sum);
        father[x] = -1;
    }
    return;
}

int main()
{
    cin >> N >> M >> S;
    for(int i = 0; i < N; ++i)
        cin >> weight[i];
    
    while(M--){
        int id, k, tmp;
        cin >> id >> k;
        while(k--){
            cin >> tmp;
            nodes[id].push_back(tmp);
        }
    }
    for(int i = 0; i < N; i++){
        if(!nodes[i].empty()){
            sort(nodes[i].begin(), nodes[i].end(), [](int a, int b){
                return weight[a] > weight[b];
            });
        }
    }
    dfs(0, 0);
    for(int i = 0; i < res.size(); ++i){
        for(int j = res[i].size()-1; j >= 0; --j){
            if(j != 0)
                cout << weight[res[i][j]] << " ";
            else
                cout << weight[res[i][j]];
        }
        if(i != res.size()-1)
            cout << endl;
    }
    return 0;
}