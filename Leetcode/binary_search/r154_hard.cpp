// 寻找旋转排序数组中的最小值--有重复
// nums[mid]==nums[l]且mid!=l时l++，即排除一个重复元素
// 这里的mid!=l是考虑只有两个元素时的情况，将mid==l归到nums[mid]>nums[l]的情况里面
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = (int)nums.size() - 1;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == nums[l] && mid != l)
                l++;
            // 这里包含了nums[mid]==nums[l]&&mid==l的情况，即只有两个元素时何时向后规约
            else if(nums[mid] >= nums[l] && nums[l] >= nums[r])
                l = mid + 1;
            else
                r = mid;
        }
        return nums[l];
    }
};