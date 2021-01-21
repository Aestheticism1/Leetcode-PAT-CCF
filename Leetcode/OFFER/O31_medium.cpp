// 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序
// 假设压入栈的所有数字均不相等
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int pos = 0;
        for(auto x: pushed){
            s.push(x);
            while(!s.empty() && s.top() == popped[pos]){
                s.pop();
                pos++;
            }
        }
        return s.empty();
    }
};