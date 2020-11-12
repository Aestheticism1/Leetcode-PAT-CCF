#include <iostream>

using namespace std;

int main()
{
    int N, M;
    cin >> N;
    int a[N+1];
    a[0] = 0;
    for(int i = 1; i <= N; ++i){
        cin >> a[i];
        a[i] += a[i-1];
    }
    
    cin >> M;
    while(M--){
        int b,c;
        cin >> b >> c;
        int k = abs(a[b-1] - a[c-1]);
        int res = min(k, a[N] - k);
        if(M!=0)
            cout << res << endl;
        else
            cout << res;
    }   
    return 0;
}