#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int p[n], t[n];
    ll res = 0;
    int cnt = 0;
    p[0] = s[0] == 'P' ? ++cnt : 0;
    for(int i = 1; i < n; ++i){
        if(s[i] == 'P'){
            p[i] = ++cnt;
        }else{
            p[i] = p[i-1];
        }
    }
    cnt = 0;
    t[n-1] = s[n-1] == 'T' ? ++cnt : 0;
    for(int i = n-2; i >= 0; --i){
        if(s[i] == 'T'){
            t[i] = ++cnt;
        }else{
            t[i] = t[i+1];
        }
    }
    for(int i = 1; i < n-1; ++i){
        if(s[i] == 'A')
            res += p[i-1]*t[i+1];
    }
    cout << res % 1000000007;
    return 0;
}