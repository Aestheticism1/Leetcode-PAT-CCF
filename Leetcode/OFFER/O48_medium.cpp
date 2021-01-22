// 最长不含重复字符的子字符串
// 滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // unordered_map<char, int> mp;
        // int res = 0, l = 0;
        // for(int i = 0; i < s.size(); i++){
        //     if(mp.find(s[i]) != mp.end())
        //         l = max(l, mp[s[i]]+1);
        //     mp[s[i]] = i;
        //     res = max(res, i-l+1);
        // }  
        // return res;      

        vector<int> mp(128, -1);
        int res = 0, l = 0;
        for(int i = 0; i < s.size(); i++){
            if(mp[s[i]] >= l)
                l = mp[s[i]] + 1;
            mp[s[i]] = i;
            res = max(res, i-l+1);
        }
        return res;
    }
};