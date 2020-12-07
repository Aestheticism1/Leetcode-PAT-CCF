#include <iostream>
using namespace std;
int A[100];
int main()
{
    string a, b;
    cin >> a >> b;
    for(int i = 0; i < b.size(); ++i){
        A[b[i]-'0']++;
    }
    for(int i = 0; i < a.size(); ++i){
        if(A[a[i]-'0'] > 0)
            A[a[i]-'0']--;
    }
    int res = 0;
    for(int i = 0; i < 100; ++i){
        res += A[i];
    }
    if(res > 0){
        cout << "No " << res;
    }else{
        cout << "Yes " << a.size() - b.size();
    }
    return 0;
}