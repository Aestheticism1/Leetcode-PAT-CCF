#include <iostream>

using namespace std;

/* 区间和 */

#define ll long long
const int N = 1100009;

struct Node{
    int l, r;
    ll val, lazy_tag;
}tree[N * 4];

void build(int l, int r, int root){
    tree[root].l = l, tree[root].r = r;
    tree[root].lazy_tag = 0;
    if(l == r){
        cin >> tree[root].val;
        return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, root<<1);
    build(mid+1, r, root<<1|1);
    tree[root].val = tree[root<<1].val + tree[root<<1|1].val;
}

void pushdown(int root){
    if(tree[root].lazy_tag){
        tree[root<<1].lazy_tag += tree[root].lazy_tag;
        tree[root<<1|1].lazy_tag += tree[root].lazy_tag;
        // 更新子节点的值（要乘区间长度）
        tree[root<<1].val += tree[root].lazy_tag * (tree[root<<1].r - tree[root<<1].l + 1);
        tree[root<<1|1].val += tree[root].lazy_tag * (tree[root<<1|1].r - tree[root<<1|1].l + 1);
        tree[root].lazy_tag = 0;
    }
}

void update(int l, int r, int root, ll v){
    if(tree[root].l >= l && tree[root].r <= r){
        // 更新当前结点的值（要乘区间长度）
        tree[root].val += v * (tree[root].r - tree[root].l + 1);
        tree[root].lazy_tag += v;
        return ;
    }
    pushdown(root);
    int mid = (tree[root].l + tree[root].r) >> 1;
    if(l <= mid)
        update(l, r, root<<1, v);
    if(r > mid)
        update(l, r, root<<1|1, v);
    
    tree[root].val = tree[root<<1].val + tree[root<<1|1].val;
}

ll query(int l, int r, int root){
    if(tree[root].l >= l && tree[root].r <= r)
        return tree[root].val;
    pushdown(root);
    ll sum = 0;
    int mid = (tree[root].l + tree[root].r) >> 1;
    if(l <= mid)
        sum += query(l, r, root<<1);
    if(r > mid)
        sum += query(l, r, root<<1|1);
    return sum;
}

int main()
{
    int n;
    cin >> n;
    build(1 , n , 1);
    update(3, 5, 1, 2);
    cout << query(3, 5, 1) << endl;
    return 0;
}