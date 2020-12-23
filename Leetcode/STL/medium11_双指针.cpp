class Solution {
public:
    /*
    在初始时，左右指针分别指向数组的左右两端
    容纳的水量 = 两个指针指向的数字中较小值 * 指针之间的距离
    */
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int m = INT_MIN;
        while(i < j){
            if(height[i] <= height[j]){
                m = max(height[i] * (j-i), m);
                i++;
            }else{
                m = max(height[j] * (j-i), m);
                j--;
            }
        }
        return m;
    }
};