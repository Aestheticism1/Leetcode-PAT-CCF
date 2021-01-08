#include <iostream>
using namespace std;

string origin, target;
int length;

// 把asdsa转为@#a#s#d#s#a#0
void getString(){
    target = "@#";
    for(int i = 0; i < origin.length(); i++){
        target += origin[i];
        target += "#";
    }
    target += "0";
    length = target.length();
}

int manacher(){
    // id为中心点，mx为右边界
    int id, mx = 0;
    int maxm = 0;
    int len[length];    // 每个字符向两侧查找的最大步长
    for(int i = 1; i < length; i++){
        // 若当前点没有超过右边界，按以下方式设置当前点的初始步长 
        // [my ... j .. id .. i ... mx]
        // 取<i关于id的对称点j的最大步长>和<i到右边界的距离>的较小值 
        if(i < mx)
            len[i] = min(len[2*id - i], mx - i);
        else
            len[i] = 1;
        
        // 查找当前点的最大步长
        while(target[i+len[i]] == target[i-len[i]])
            len[i]++;

        // 若当前点查找到的右边界 > 已知右边界，则更新中心点和右边界
        if(mx < i + len[i]){
            id = i;
            mx = i + len[i];
            maxm = max(maxm, len[i]);
        }
    }
    return maxm - 1;
}

int main()
{
    cin >> origin;
    getString();
    int res = manacher();
    cout << res << endl;
    return 0;
}