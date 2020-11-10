#include <iostream>
/* Longest Symmetric String */
using namespace std;

// 学习
void better(){
    string s;
    getline(cin,s);
    int maxLen=0;
    for(int i=0;i<s.size();++i){
        int j;
        for(j=1;i-j>=0&&i+j<s.size()&&s[i+j]==s[i-j];++j);//以当前字符为回文中心查找最长回文子串
        maxLen=max(maxLen,2*j-1);//更新回文子串最大长度
        for(j=0;i-j>=0&&i+j+1<s.size()&&s[i-j]==s[i+1+j];++j);//以当前字符为回文中心左侧字符查找最长回文子串
        maxLen=max(maxLen,2*j);//更新回文子串最大长度
    }
    printf("%d",maxLen);
}

// mine
string s;
int cnt(int l, int r){
    while(l >= 0 && r < s.size() && s[l] == s[r]){
        l--;
        r++;
    }
    return r-l-1;
}

int main()
{
    getline(cin, s);
    int min = 1;
    for(int i = 0; i < s.size()-1; i++){
        if(s[i] != s[i+1]){
            int tmp = cnt(i, i);
            if(tmp > min)
                min = tmp;
        }else{
            int tmp = max(cnt(i, i), cnt(i, i+1));
            if(tmp > min)
                min = tmp;
        }
    }
    cout << min;
    return 0;
}