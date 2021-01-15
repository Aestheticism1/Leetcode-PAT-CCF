// 山脉数组中查找目标值
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int bin_search1(int target, MountainArray &mountainArr, int left, int right){
        while(left < right){
            int mid = left + (right - left) / 2;
            if(mountainArr.get(mid) < target)
                left = mid + 1;
            else
                right = mid;
        }
        if(mountainArr.get(left) != target)
            return -1;
        return left;
    }

    int bin_search2(int target, MountainArray &mountainArr, int left, int right){
        while(left < right){
            int mid = left + (right - left + 1) / 2;
            if(mountainArr.get(mid) < target)
                right = mid - 1;
            else
                left = mid;
        }
        if(mountainArr.get(left) != target)
            return -1;
        return left;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l = 0, r = n-1;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1))
                l = mid + 1;
            else
                r = mid;
        }
        int res = bin_search1(target, mountainArr, 0, l);
        if(res == -1)
            res = bin_search2(target, mountainArr, l+1, n-1);
        
        return res;
    }
};