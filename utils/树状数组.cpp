#include <iostream>
#include <cstring>

using namespace std;

const int L = 10005;

int n;
int a[L], c[L];

// 取i的 2的最大次方 的因子
int lowbit(int i){
    return i&(-i);
}

// 更新
void update(int i, int k){
    while(i <= n){
        c[i] += k;
        i += lowbit(i);
    }
}

// 求和
int getsum(int i){
    int res = 0;
    while(i > 0){
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}

// 单点更新，区间查询
int bit1(){
    cin >> n;
    fill(a, a+L, 0); fill(c, c+L, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        // 建树状数组c[L]
        update(i, a[i]);
    }

    // 查询[x,y]区间和
    int x, y;
    cin >> x >> y;
    int sum = getsum(y) - getsum(x-1);
    return sum;
}

// 区间更新，单点查询
// A[i] = Σj=(1=>i) D[j]
// 即D[j] = A[j] - A[j-1]
// 不再直接对A建树，转而对D建树
int bit2(){
    cin >> n;
    fill(a, a+L, 0); fill(c, c+L, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        // 建树状数组c[L]
        update(i, a[i] - a[i-1]);
    }

    // 在区间[x,y]上加上k
    int x, y, k;
    cin >> x >> y >> k;
    update(x, k);
    update(y+1, -k);

    // 查询a[index]
    int index;
    cin >> index;
    int sum = getsum(index);

    return sum;
}

/* 查询与更新操作与前面两种不一样*/

// 区间更新，区间查询
// ∑i=(1=>n) A[i] = ∑i=(1=>n) ∑j=(1=>i) D[j]
// ∑i=(1=>n) A[i] = n * ∑i=(1=>n) D[i] - ∑i=(1=>n) (D[i]*(i-1))
// 所以对 D[i] 和 D[i]*(i-1) 建树
int m;
int A[L], D1[L], D2[L];

void update2(int i, int k){
    int j = i;
    while(i <= m){
        D1[i] += k;
        D2[i] += k * (j-1);
        i += lowbit(i);
    }
}

int getsum2(int i){
    int res = 0, j = i;
    while(i > 0){
        res += j * D1[i] - D2[i];
        i -= lowbit(i);
    }
    return res;
}

int bit3(){
    cin >> m;
    fill(A, A+L, 0); fill(D1, D1+L, 0); fill(D2, D2+L, 0);
    for(int i = 1; i <= m; i++){
        cin >> A[i];
        // 建树状数组 D1[L] 和 D2[L]
        update2(i, A[i] - A[i-1]);
    }

    // 在区间[x,y]上加上k
    int x, y, k;
    cin >> x >> y >> k;
    update2(x, k);
    update2(y+1, -k);

    // 求[xx,yy]区间和
    int xx, yy;
    cin >> xx >> yy;
    int sum = getsum2(yy) - getsum2(xx - 1);

    return sum;
}

int main()
{
    cout << bit1() << endl;    // 单点更新，区间查询
    cout << bit2() << endl;    // 区间更新，单点查询
    cout << bit3() << endl;    // 区间更新，区间查询
    return 0;
}