#include <iostream>
#include <vector>
using namespace std;

/*
获得最大上升子序列
例：[7,6,2,1,3,5,4] => [[2,3,5],[2,3,4]]
dp[i]表示以nums[i]结尾的最长升序子序列长度
加了一个LIS数组保存到当前元素为止最长的子序列
*/

int n;
vector<vector<int> > LIS;

int LIS_Seq(int nums[], int dp[]){
    if(n < 2)
        return n;
    LIS = {{nums[0]}};
    int res = 1;
    for(int i = 1; i < n; i++){
        int max_val = 0;
        int max_index = -1;
        for(int j = 0; j < i; j++){
            if(nums[j] < nums[i] && dp[j] > max_val){
                max_index = j;
                max_val = dp[j];
            }
        }
        if(max_index != -1){
            vector<int> tmp = LIS[max_index];
            tmp.push_back(nums[i]);
            LIS.push_back(tmp);
        }else
            LIS.push_back({nums[i]});
        dp[i] = max_val + 1;
        res = max(res, dp[i]);
    }

    // 然后搜索LIS，把最长的取出即可
    return res;
}

int main()
{
    cin >> n;
    int nums[n];
    int dp[n];
    fill(dp, dp+n, 1);
    for(int i = 0; i < n; i++)
        cin >> nums[i];
    int res = LIS_Seq(nums, dp);
    cout << res << endl;
    for(int i = 0; i < LIS.size(); i++){
        for(int j = 0; j < LIS[i].size(); j++)
            cout << LIS[i][j] << " ";
        cout << endl;
    }
    return 0;
}