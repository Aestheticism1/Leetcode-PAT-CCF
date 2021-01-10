class Solution {
public:
    /**
     * 二分查找
     * @param n int整型 数组长度
     * @param v int整型 查找值
     * @param a int整型vector 有序数组
     * @return int整型
     */
    int upper_bound_(int n, int v, vector<int>& a) {
        // write code here
        if(a[n-1] < v)
            return n+1;
        int left = 0;
        int right = n-1;
        // 当left == right时找到
        while(left < right){
            int mid = (left + right) / 2;
            if(a[mid] >= v)
                right = mid;
            else
                left = mid + 1;
        }
        return left + 1;
    }
};