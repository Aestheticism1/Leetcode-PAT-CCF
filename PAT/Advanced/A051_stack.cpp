#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int M, N, K;
    cin >> M >> N >> K;
    int a[N];
    bool res[K];
    fill(res, res+K, true);
    for(int k = 0; k < K; ++k){
        for(int i = 0; i < N; ++i)
            cin >> a[i];
        stack<int> s;
        int index = 0;
        for(int i = 0; i < N; ++i){
            if(index < a[i]){
                if(a[i] - index + s.size() > M){
                    res[k] = false;
                    break;
                }
                for(int j = index+1; j < a[i]; ++j){
                    s.push(j);
                }
                index = a[i];
            }else{
                if(s.empty() || s.top() != a[i]){
                    res[k] = false;
                    break;
                }
                s.pop();
            }
        }
    }

    for(int i = 0; i < K; ++i){
        if(i != K-1)
            res[i] ? cout << "YES" << endl : cout << "NO" << endl;
        else
            res[i] ? cout << "YES" : cout << "NO";
    }
    return 0;
}