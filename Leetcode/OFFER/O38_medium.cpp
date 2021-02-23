// 字符串全排列
// 1、终止条件：当 x=len(c)−1 时，代表所有位已固定（最后一位只有1种情况），则将当前字符串加入res，并返回
// 2、递推参数：当前固定位x
// 3、初始化一个Set，用于排除重复的字符；将第 x 位字符与 i ∈ [x,len(c)) 字符分别交换，并进入下层递归
//      1、剪枝：若 c[i] 在 Set​ 中，代表其是重复字符，因此“剪枝”；
//      2、将 c[i] 加入 Set​，以便之后遇到重复字符时剪枝；
//      3、固定字符：将字符 c[i] 和 c[x] 交换，即固定 c[i] 为当前位字符；
//      4、开启下层递归：调用 dfs(x+1)，即开始固定第 x+1 个字符；
//      5、还原交换：将字符 c[i] 和 c[x] 交换（还原之前的交换）；
class Solution {
public:
    // x表示固定第几位
    void dfs(string s, int x, vector<string>& res){
        if(x == s.size() - 1){
            res.push_back(s);
            return;
        }
        unordered_set<char> tmp;
        for(int i = x; i < s.size(); i++){
            if(tmp.find(s[i]) != tmp.end())
                continue;
            tmp.insert(s[i]);
            swap(s[x], s[i]);
            dfs(s, x + 1, res);
            swap(s[x], s[i]);
        }
    }

    vector<string> permutation(string s) {
        vector<string> res;
        dfs(s, 0, res);
        return res;
    }
};