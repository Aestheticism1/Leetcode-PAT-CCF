#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    return b==0 ? a : gcd(b, a%b);
}

int main()
{
    int N;
    cin >> N;
    ll rn, rd;
    scanf("%lld/%lld", &rn, &rd);
    for(int i = 0; i < N-1; ++i){
        int n, d;
        scanf("%d/%d", &n, &d);
        rn = rn * d + n * rd;
        rd *= d;
    }
    if(rn == 0){
        printf("%lld", rn);
    }else if(rn % rd == 0){
        printf("%lld", rn/rd);
    }else{
        if(rn > rd){
            printf("%lld ", rn/rd);
            rn %= rd;
        }
        ll a = gcd(rn, rd);
        printf("%lld/%lld", rn/a, rd/a);
    }

    return 0;
}