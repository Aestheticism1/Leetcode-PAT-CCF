#include <iostream>

using namespace std;

typedef long long ll;
const int L = 2e5 + 5;
ll a[L], b[L];
int N, M;

ll find(int aa, int bb, int k){
    if(aa == N)
        return b[bb+k-1];
    if(bb == M)
        return a[aa+k-1];
    if(k == 1)
        return min(a[aa], b[bb]);
    int e = k / 2;
    int indexA = min(aa+e-1, N-1);
    int indexB = min(bb+e-1, M-1);
    if(a[indexA] <= b[indexB])
        return find(indexA+1, bb, k-indexA+aa-1);
    else
        return find(aa, indexB+1, k-indexB+bb-1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> a[i];
    cin >> M;
    for(int i = 0; i < M; ++i)
        cin >> b[i];
    int K = (M + N + 1) / 2;
    cout << find(0, 0, K);
    return 0;
}