#include <iostream>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int A[N];
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    sort(A, A+N);
    int res = -1;
    for(int i = 0; i < N-1; ++i){
        if(binary_search(A+i+1, A+N, M-A[i])){
            res = A[i];
            break;
        }
    }
    if(res == -1)
        cout << "No Solution";
    else
        cout << res << " " << M - res;
    return 0;
}