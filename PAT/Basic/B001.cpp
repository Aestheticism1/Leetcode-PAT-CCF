#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, ans = 0;
    cin >> n;
    for (; n != 1; ++ans) {
        if (n & 1) {
            n = 3 * n + 1;
        }
        n >>= 1;
    }
    cout << ans << endl;
    return 0;
}