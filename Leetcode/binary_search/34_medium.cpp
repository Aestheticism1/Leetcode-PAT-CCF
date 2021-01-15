// 在排序数组中查找元素的第一个和最后一个位置
class Solution {
private:
    int findFitstPosition(vector<int> &nums, int target) {
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] == target){
                right = mid;
            } else {
                // nums[mid] > target
                right = mid - 1;
            }
        }
        if (nums[left] != target) {
            return -1;
        }
        return left;
    }

    int findLastPosition(vector<int> &nums, int target) {
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] == target){
                left = mid;
            } else {
                // nums[mid] < target
                left = mid + 1;
            }
        }
        if (nums[left] != target) {
            return -1;
        }
        return left;
    }


public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int size = nums.size();
        if (size == 0) {
            return {-1, -1};
        }
        int fitstPosition = findFitstPosition(nums, target);

        if (fitstPosition == -1) {
            return {-1, -1};
        }
        int lastPosition = findLastPosition(nums, target);
        return {fitstPosition, lastPosition};
    }
};
