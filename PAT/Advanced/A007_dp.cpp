#include <iostream>
#include <vector>

using namespace std;

// 最大子串和
// 状态转移方程：dp[i] = max(dp[i-1] + a[i], a[i])

int main()
{
    int K;
    vector<int> a;
    cin >> K;
    a.push_back(0);
    int t = K;
    bool flag = false;
    while(t--){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
        if(tmp >= 0)
            flag = true;
    }

    if(!flag){
        cout << "0 " << a[1] << " " << a[K];
        return 0;
    }
    
    int dp[K+2];
    dp[0] = 0;
    int ans = INT_MIN;
    int end = 0;
    for(int i = 1; i <= K; i++){
        dp[i] = max(dp[i-1] + a[i], a[i]);
        if(dp[i] > ans){
            end = i;
            ans = dp[i];
        }
    }
    cout << ans << " ";
    for(int i = end; i >= 1; i--){
        if(ans - a[i] == 0){
            cout << a[i] << " ";
            break;
        }
        ans -= a[i];
    }
    cout << a[end];
    return 0;
}