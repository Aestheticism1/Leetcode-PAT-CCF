#include <iostream>

using namespace std;

// 满分代码，学习
int correct(){
    int N,ans=0;
    scanf("%d",&N);
    int left=N/10,right=0,current=N%10;
    for (int i=1;right!=N;i*=10) {
        ans+=left*i+(current==0?0:current==1?(right+1):i);
        right+=current*i;
        current=left%10;
        left/=10;
    }
    printf("%d",ans);
    return 0;
}

// 22分代码
int main()
{
    int N;
    cin >> N;
    int dp[N+1];
    fill(dp, dp+N+1, 0);
    dp[1] = 1;
    if(N < 10){
        cout << 1;
        return 0;
    }
    for(int i = 10; i <= N; ++i){
        string s = to_string(i);
        char f = s[0];
        s = s.substr(1, s.length() - 1);
        if(f != '1')
            dp[i] = dp[stoi(s)];
        else
            dp[i] = dp[stoi(s)] + 1; 
    }
    int res = 1;
    for(int i = 10; i <= N; ++i)
        res += dp[i];
    cout << res;
    return 0;
}