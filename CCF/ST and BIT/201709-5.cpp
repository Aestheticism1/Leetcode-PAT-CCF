#include <iostream>

using namespace std;

const int L = 100005;

int n, m;
int a[L];
long long c[L];

/* 树状数组 */
int lowbit(int i){
    return i&(-i);
}

void update(int i, int k){
    while(i <= n){
        c[i] += k;
        i += lowbit(i);
    }
}

long long getsum(int i){
    long long res = 0;
    while(i > 0){
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        update(i, a[i]);
    }

    while(m--){
        int option, l, r, v;
        cin >> option >> l >> r;
        if(option == 1){
            cin >> v;
            if(v == 1) continue;    // 这行不加会超时
            for(int i = l; i <= r; i++){
                if(a[i] >= v && a[i] % v == 0){  // 这里不加a[l]>=v会超时。用a[l]代替a[l]>=v会慢5s多，险些超时
                    update(i, a[i]/v - a[i]);
                    a[i] /= v;
                }
            }
        }else{
            cout << getsum(r) - getsum(l-1) << endl;
        }
    }
    
    return 0;
}