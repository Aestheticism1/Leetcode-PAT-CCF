#include <iostream>
#include <vector>

using namespace std;

/*
问题：寻找两个正序数组的中位数
题目要求时间复杂度O(log(m+n))，对时间复杂度的要求有log，通常要用到二分查找
整体思路：将问题转化为找第k大的数，初始k=(m+n+1)/2，m+n为奇数时找第k大，偶数时找第k大和第k+1大取平均
如何找第k大：
    1、比较nums1[offset1 + k/2-1]和nums2[offset2 + k/2-1]
    2、哪个小就从哪个数组中排除 k/2-1 个数
    3、更新k值和offset
    4、三种边界情况：nums1越界、nums2越界、k==1
*/

int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k){
    int m = nums1.size(), n = nums2.size();
    int index1 = 0, index2 = 0;
    while(true){
        // 边界情况
        if(index1 == m)
            return nums2[index2 + k - 1];
        if(index2 == n)
            return nums1[index1 + k - 1];
        if(k == 1)
            return min(nums1[index1], nums2[index2]);
        
        // 正常情况
        int new_index1 = min(index1 + k/2 - 1, m - 1);
        int new_index2 = min(index2 + k/2 - 1, n - 1);
        if(nums1[new_index1] >= nums2[new_index2]){
            k -= new_index2 - index2 + 1;
            index2 = new_index2 + 1;
        }else{
            k -= new_index1 - index1 + 1;
            index1 = new_index1 + 1;
        }
    }
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    int size = nums1.size() + nums2.size();
    int k = (size + 1) >> 1;
    if(size & 1)
        return getKthElement(nums1, nums2, k);
    else
        return (getKthElement(nums1, nums2, k) + getKthElement(nums1, nums2, k+1)) / 2.0;
}

int main()
{
    vector<int> nums1 = {1, 3, 4, 9};
    vector<int> nums2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}