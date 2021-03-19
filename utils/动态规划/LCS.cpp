// 最长公共子序列
// dp[i][j]表示s1到第i个字符和s2到第j个字符的LCS长度
// 状态转移方程：
// s1[i] == s2[j], dp[i][j] = dp[i-1][j-1] + 1
// s1[i] != s2[j], dp[i][j] = max(dp[i-1][j], dp[i][j-1])
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = (int)text1.size(), len2 = (int)text2.size();
        int dp[len1+1][len2+1];
        for(int i = 0; i <= len1; i++){
            for(int j = 0; j <= len2; j++){
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
                else if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[len1][len2];
    }
};