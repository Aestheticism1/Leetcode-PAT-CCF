#include <iostream>

using namespace std;

/* 以区间最大值为例 */

const int MAX = 100005;
const int INF = numeric_limits<int>::max();
int a[MAX], t[MAX<<2];

// 更新函数，这里实现最大值、最小值、区间和等
void Pushup(int k){
    t[k] = max(t[k<<1], t[k<<1|1]);
}

// 递归建树
// k为当前需要建立的结点，l为当前需要建立区间的左端点，r则为右端点
void build(int l, int r, int k)
{
    if(l == r)
        t[k] = a[l];
    else{
        int m = l + ((r - l) >> 1);
        build(l, m, k<<1);
        build(m+1, r, k<<1|1);
        Pushup(k);
    }
}

/* 单点更新 */
void update_single(int p, int v, int l, int r, int k){
    if(l == r){
        a[k] += v;
        t[k] += v;
    }else{
        int m = l + ((r - l) >> 1);
        if(p <= m)
            update_single(p, v, l, m, k<<1);
        else
            update_single(p, v, m+1, r, k<<1|1);
        Pushup(k);
    }
}

// 区间查询-无lazy_tag
int query(int L, int R, int l, int r, int k){
    if(l >= L && r <= R)    // 如果当前结点的区间包含于要更新的区间
        return t[k];
    else{
        int res = -INF;
        int m = l + ((r - l) >> 1);
        if(L <= m)
            res = max(res, query(L, R, l, m, k<<1));
        if(R > m)
            res = max(res, query(L, R, m+1, r, k<<1|1));
        return res;
    }
}

/* 区间更新 */
// 懒惰标记，更新到结点区间为需要更新的区间的子集时不再往下更新，
// 下次若是遇到需要用这下面的结点的信息，再去更新这些结点
int lazy[MAX<<2];   

void Pushdown(int k){   // 更新子树的lazy值，要实现区间和等需要修改函数
    if(lazy[k]){
        lazy[k<<1] += lazy[k];
        lazy[k<<1|1] += lazy[k];
        t[k<<1] += lazy[k];     // 左子树的最值加上lazy值
        t[k<<1|1] += lazy[k];   // 右子树的最值加上lazy值
        lazy[k] = 0;
    }
}

void update_range(int L, int R, int v, int l, int r, int k){
    if(l >= L && r <= R){   // 如果当前结点的区间包含于要更新的区间
        lazy[k] += v;
        t[k] += v;      // 此区间每个值+v,则此区间的最大值也肯定是+v
    }else{
        Pushdown(k);    // 查询lazy标记，先更新子树
        int m = l + ((r - l) >> 2);
        if(L <= m)
            update_range(L, R, v, l, m, k<<1);
        if(R > m)
            update_range(L, R, v, m+1, r, k<<1|1);
        Pushup(k);
    }
}

// 区间查询-有lazy_tag
int query_lazy(int L, int R, int l, int r, int k){
    if(l >= L && r <= R){
        return t[k];
    }else{
        Pushdown(k);
        int res = -INF;
        int m = l + ((r - l) >> 1);
        if(L <= m)
            res = max(res, query_lazy(L, R, l, m, k<<1));
        if(R > m)
            res = max(res, query_lazy(L, R, m+1, r, k<<1|1));
        return res;
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    build(1, n, 1);
    update_single(3, 2, 1, n, 1);
    cout << query(3, 3, 1, n, 1) << endl;
    update_range(2, 4, 2, 1, n, 1);
    cout << query_lazy(2, 4, 1, n, 1) << endl;
    return 0;
}