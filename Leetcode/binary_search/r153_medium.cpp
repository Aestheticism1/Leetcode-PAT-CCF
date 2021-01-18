// 寻找旋转排序数组中的最小值--无重复
// nums[mid] >= nums[l]说明[l, mid]是升序，此时当nums[l] > nums[r]时向后规约
// 其他情况下向前规约
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = (int)nums.size() - 1;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[mid] >= nums[l] && nums[l] > nums[r])
                l = mid + 1;
            else
                r = mid;
        }
        return nums[l];
    }
};