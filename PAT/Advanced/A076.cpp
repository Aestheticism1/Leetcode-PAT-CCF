#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int N, L;
    cin >> N >> L;
    vector<int> user[N+1];
    for(int i = 1; i <= N; ++i){
        int num, tmp;
        cin >> num;
        while(num--){
            cin >> tmp;
            user[tmp].push_back(i);
        }
    }
    int K, p;
    bool A[N+1];
    queue<pair<int, int>> q;
    cin >> K;
    while(K--){
        cin >> p;
        fill(A, A+N+1, false);
        q.push({p, 0});
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            if(!A[top.first]){
                if(top.second < L){
                    for(auto x: user[top.first]){
                        if(!A[x]){
                            q.push({x, top.second+1});
                        }
                    }
                }
                A[top.first] = true;
            }
        }
        int cnt = 0;
        for(int i = 1; i <= N; ++i)
            if(A[i])
                cnt++;
        cout << cnt - 1 << endl;
    }
    return 0;
}