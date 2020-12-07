#include <iostream>
#include <vector>
using namespace std;

const int L = 1e5+5;
int N;
double P, R;
vector<vector<int> > g(L);
double maxp = INT_MIN * 1.0;
int cnt = 0;

void dfs(int root, double p){
    if(p > maxp){
        maxp = p;
        cnt = 1;
    }else if(p == maxp){
        cnt++;
    }
    for(auto x: g[root])
        dfs(x, p*(1+R/100));
}

int main()
{
    cin >> N >> P >> R;   
    int root;
    for(int i = 0; i < N; ++i){
        int tmp;
        cin >> tmp;
        if(tmp == -1)
            root = i;
        else
            g[tmp].push_back(i);
    }
    dfs(root, P);
    printf("%.2lf %d", maxp, cnt);
    return 0;
}