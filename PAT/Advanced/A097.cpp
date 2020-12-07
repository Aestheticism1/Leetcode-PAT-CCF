#include <iostream>
#include <vector>
using namespace std;
const int L = 1e5+5;
const int LL = 1e4+5;
int Data[L], Next[L];
bool mark[LL];
int main() 
{
    int first, N;
    cin >> first >> N;
    for(int i = 0; i < N; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        Data[a] = b;
        Next[a] = c;
    }
    vector<int> A, B;
    while(first != -1){
        if(!mark[abs(Data[first])]){
            mark[abs(Data[first])] = true;
            A.push_back(first);
        }else{
            B.push_back(first);
        }
        first = Next[first];
    }
    for(int i = 0; i < A.size(); ++i){
        printf("%05d %d ", A[i], Data[A[i]]);
        if(i+1 != A.size())
            printf("%05d\n", A[i+1]);
        else
            printf("-1\n");
    }
    for(int i = 0; i < B.size(); ++i){
        printf("%05d %d ", B[i], Data[B[i]]);
        if(i+1 != B.size())
            printf("%05d\n", B[i+1]);
        else
            printf("-1\n");
    }
    return 0;
}