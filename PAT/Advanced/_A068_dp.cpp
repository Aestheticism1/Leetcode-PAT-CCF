#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1);
    vector<bitset<105>> dp(n + 1), select(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    sort(v.begin() + 1, v.end(), greater<int>());
    dp[0][0] = select[0][0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - v[i]];
                if (dp[i - 1][j - v[i]])
                    select[i][j] = true;
            }
        }
    }
    if (!dp[n][m]) {
        cout << "No Solution";
    } else {
        bool output = false;
        for (int i = n; i >= 1; --i)
            if (select[i][m]) {
                cout << (output ? " " : "") << v[i];
                m -= v[i];
                output = true;
            }
    }
    return 0;
}