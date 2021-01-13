// 复杂度O(n^2)
// dp[i]表示以nums[i]结尾的最长升序子序列长度
// 状态转移方程 dp[i] = max(dp[i], dp[j] + 1)
class Solution { 
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = (int)nums.size();
        if(n < 1)
            return 0;
        int dp[n];
        for(int i = 0; i < n; i++){
            dp[i] = 1;
            for(int j = 0; j < i; j++)
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
        }
        return *max_element(dp, dp+n);
    }
};

// 复杂度O(nlogn)--动态规划+二分查找
// 数组dp保存到当前元素为止的最长升序子序列
// 若新元素大于dp最后一个元素，直接将其添加到dp尾部
// 若新元素小于等于dp最后一个元素，用二分查找找到dp中第一个大于等于它的数，并用它替代原来的数
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = (int)nums.size();
        if(n < 1)
            return 0;
        vector<int> dp;
        dp.push_back(nums[0]);
        int len = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] > dp[(int)dp.size() - 1]){
                dp.push_back(nums[i]);
                len++;
            }else{
                int left = 0, right = (int)dp.size()-1;
                while(left < right){
                    int mid = left + (right - left) / 2;
                    if(dp[mid] < nums[i])
                        left = mid + 1;
                    else
                        right = mid;
                }
                dp[left] = nums[i];
            }
        }
        return len;
    }
};