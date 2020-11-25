#include <iostream>

using namespace std;
const int L = 105;

int main()
{
    int N;
    cin >> N;
    int origin[L], copy[L], target[L];
    for(int i = 0; i < N; ++i)
        scanf("%d", &origin[i]);
    for(int i = 0; i < N; ++i)
        scanf("%d", &target[i]);
    memcpy(copy, origin, sizeof(origin));
    bool flag = false;
    for(int i = 1; i < N; ++i){
        sort(copy, copy+i+1);
        if(equal(copy, copy+N, target)){
            flag = true;
            printf("Insertion Sort\n");
            sort(copy, copy+i+2);
            break;
        }
    }
    if(!flag){
        printf("Merge Sort\n");
        memcpy(copy, origin, sizeof(origin));
        for(int i = 2; i < N; i*=2){    
            for(int j = 0; j < N; j+=i)
                sort(copy+j, j+i < N ? copy+j+i : copy+N);
            if(equal(copy, copy+N, target)){
                i *= 2;
                for(int j = 0; j < N; j+=i)
                    sort(copy+j, j+i < N ? copy+j+i : copy+N);
                break;
            }
        }
    }
    for(int i = 0; i < N; ++i)
        printf("%s%d", i==0 ? "" : " ", copy[i]);
    return 0;
}