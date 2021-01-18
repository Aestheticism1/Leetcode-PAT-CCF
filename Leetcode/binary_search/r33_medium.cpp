// 搜索旋转排序数组--有重复
// nums[mid] >= nums[l]说明[l, mid]是升序，此时当target > nums[mid] || target < nums[l]时向后规约
// nums[mid] < nums[l]说明[l, mid]存在旋转位，此时当target > nums[mid] && target < nums[l]时向后规约
// 其他情况下向前规约
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = (int)nums.size() - 1;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[mid] >= nums[l] && (target > nums[mid] || target < nums[l]))
                l = mid + 1;
            else if(nums[mid] < nums[l] && (target > nums[mid] && target < nums[l]))
                l = mid + 1;
            else
                r = mid;
        }
        return nums[l] == target ? l : -1;
    }
};