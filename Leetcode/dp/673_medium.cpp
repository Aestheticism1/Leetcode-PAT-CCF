// 在LIS的基础上加了dp_num数组来保存到当前元素为止的LIS的数量
// 1.在nums[i] > nums[j]前提下，如果在[0, i-1]的范围内，找到了j，使得dp[j] + 1 > dp[i]，说明找到了一个更长的递增子序列。
// 以j为结尾的子串的最长递增子序列的个数，就是最新的以i为结尾的子串的最长递增子序列的个数，即：count[i] = count[j]。
// 2.在nums[i] > nums[j]前提下，如果在[0, i-1]的范围内，找到了j，使得dp[j] + 1 == dp[i]，说明找到了两个相同长度的递增子序列。
// 以i为结尾的子串的最长递增子序列的个数 就应该加上以j为结尾的子串的最长递增子序列的个数，即：count[i] += count[j]。

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = (int)nums.size();
        if(n < 2)
            return n;
        vector<int> dp(n, 1);
        vector<int> dp_num(n, 1);
        int ans = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        dp_num[i] = dp_num[j];
                    }else if(dp[i] == dp[j] + 1){
                        dp_num[i] += dp_num[j];
                    }
                }
            }
            ans = max(ans, dp[i]);
        }
        int res = 0;
        for(int i = 0; i < n; i++)
            if(dp[i] == ans)
                res += dp_num[i];
        return res;
    }
};