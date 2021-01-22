// 剪绳子
// 长度为n，剪成整数长度的m段，使乘积最大
// 剪成越多个长度为3的段越好
class Solution {
public:
    int cuttingRope(int n) {
        if(n <= 3) return n - 1;
        if(n % 3 == 0) return pow(3, n/3);
        if(n % 3 == 1) return pow(3, n/3 - 1) * 4;
        return pow(3, n/3) * 2;
    }
};