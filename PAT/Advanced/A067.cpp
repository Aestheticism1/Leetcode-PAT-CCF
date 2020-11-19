#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int index[N];
    int cnt = N-1;
    int res = 0;
    int tmp;
    for(int i = 0; i < N; ++i){
        cin >> tmp;
        index[tmp] = i;
        if(tmp == i && tmp != 0)
            cnt--;
    }
    int k = 1;
    while(cnt > 0){
        if(index[0] == 0){
            while(k < N){
                if(index[k] != k){
                    swap(index[0], index[k]);
                    res++;
                    break;
                }
                k++;
            }
        }
        while(index[0] != 0){
            swap(index[0], index[index[0]]);
            res++;
            cnt--;
        }
    }
    cout << res;

    return 0;
}