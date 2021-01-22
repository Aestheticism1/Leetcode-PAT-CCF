// 最小覆盖子串
// 输入：s = "ADOBECODEBANC", t = "ABC"
// 输出："BANC"

// 滑动窗口
class Solution {
private:
    unordered_map<char, int> target, search;
public:
    bool check(){
        for(auto& x: target){
            if(x.second > search[x.first])
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        for(int i = 0; i < t.size(); i++){
            target[t[i]]++;
        }
        int l = 0, ansL = -1, len = INT_MAX;
        for(int r = 0; r < s.size(); r++){
            search[s[r]]++;
            while(check()){
                // 这里保存最小覆盖字串的起点和长度
                if(r - l + 1 < len){
                    len = r - l + 1;
                    ansL = l;
                }
                search[s[l++]]--;
            }
        }
        return ansL == -1 ? string() : s.substr(ansL, len);
    }
};