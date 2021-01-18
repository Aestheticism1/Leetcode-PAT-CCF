// 搜索旋转排序数组--有重复
// 与无重复主要区别在于nums[mid]==nums[l]的时候l++，即排除一个重复元素
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = (int)nums.size() - 1;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == target)
                return true;
            if(nums[mid] == nums[l])
                l++;
            else if(nums[mid] > nums[l] && (target > nums[mid] || target < nums[l]))
                l = mid + 1;
            else if(nums[mid] < nums[l] && (target > nums[mid] && target < nums[l]))
                l = mid + 1;
            else
                r = mid;
        }
        return nums[l] == target ? true : false;
    }
};