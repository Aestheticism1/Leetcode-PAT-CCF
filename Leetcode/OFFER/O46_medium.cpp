// 动态规划 + 滚动数组
// 状态转移方程：f(i) = f(i-1) + f(i-2)，所以用滚动数组
// 单独翻译对f(i)的贡献为f(i−1)
// 如果第i-1位与第i位形成的数字x满足10<=x<=25，则可以一起翻译，对f(i)的贡献为f(i-2)
class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        int p = 0, q = 0, r = 1;
        for(int i = 0; i < (int)s.size(); i++){
            p = q;
            q = r;
            r = 0;
            r += q;
            if(i == 0)
                continue;
            string tmp = s.substr(i-1, 2);
            if(tmp >= "10" && tmp <= "25"){
                r += p;
            }
        }
        return r;
    }
};