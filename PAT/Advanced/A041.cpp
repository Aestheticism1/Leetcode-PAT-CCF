#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int a[N+5];
    unordered_map<int, int> hash;
    for(int i = 0; i < N; ++i){
        cin >> a[i];
        hash[a[i]]++;
    }
    bool flag = false;
    for(int i = 0; i < N; ++i){
        if(hash[a[i]] == 1){
            flag = true;
            cout << a[i];
            break;
        }
    }
    if(!flag){
        cout << "None";
    }
    
    return 0;
}