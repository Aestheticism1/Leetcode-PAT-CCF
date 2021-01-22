// 丑数
// 只包含质因子 2、3 和 5 的数

// 状态转移方程：dp[i] = min(dp[a]×2, dp[b]×3, dp[c]×5)
// 索引 a, b, c 需满足以下条件：
// dp[a]×2 > dp[i−1] ≥ dp[a−1]×2
// dp[b]×3 > dp[i−1] ≥ dp[b−1]×3
// dp[c]×5 > dp[i−1] ≥ dp[c−1]×5
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        int a = 0, b = 0, c = 0;
        for(int i = 1; i < n; i++){
            int n2 = dp[a] * 2, n3 = dp[b] * 3, n5 = dp[c] * 5;
            dp[i] = min(n2, min(n3, n5));
            if(dp[i] == n2) a++;
            if(dp[i] == n3) b++;
            if(dp[i] == n5) c++;
        }
        return dp[n-1];
    }
};