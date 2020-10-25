#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/* 哈希表，时间O(n)，空间O(n) */
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hash;
    for(int i = 0; i < nums.size(); i++){
        auto it = hash.find(target - nums[i]);
        if(it != hash.end())
            return {it->second, i};
        hash[nums[i]] = i;
    }
    return {};
}

int main() 
{
    vector<int> nums = {2, 7, 11, 15};
    vector<int> ans = twoSum(nums, 13);
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}

