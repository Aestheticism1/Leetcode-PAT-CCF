#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/* 单调栈，栈中元素只增不减*/
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    // 整体思路：从高度出发找宽度，即找每个柱子的左右最大宽度
    // 柱子i的左边界，left[i]表示i左边最近的高度 < heights[i]的柱子下标
    // 柱子i的右边界，right[i]表示i右边最近的高度 <= heights[i]的柱子下标，这里的等号不会影响最终结果，可细品
    // 这里初始化right每个元素都为n，是因为循环结束时栈中若还有元素，这些元素的右边界都为n
    // -1,[0,1,...,n-1],n
    // -1和n是两个虚拟的柱子，称为哨兵，可细品
    vector<int> left(n), right(n, n);
    stack<int> a;
    for(int i = 0; i < n; i++){
        // 出栈，直到找到i左边第一个比heights[i]严格小的柱子
        while(!a.empty() && heights[a.top()] >= heights[i]){
            // 出栈元素a.top()的右边界即为入栈元素i
            right[a.top()] = i;
            a.pop();
        }
        // 入栈元素i的左边界即为栈顶元素
        left[i] = a.empty() ? -1 : a.top();
        a.push(i);
    }

    // 根据right和left数组即可得到每个柱子对应的宽，从而得到面积
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, heights[i] * (right[i] - left[i] - 1));
    
    return ans;
}

int main()
{
    vector<int> x = {2,1,5,6,2,3};
    cout << largestRectangleArea(x) << endl;

    return 0;
}