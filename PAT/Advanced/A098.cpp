#include <iostream>
using namespace std;
const int maxn = 105;
int origin[maxn], target[maxn], insert[maxn], heap[maxn], N;
void downAdjust(int low, int high){
    int i = low, j = i * 2;
    while(j <= high){
        if(j + 1 <= high && heap[j+1] > heap[j])
            j = j + 1;
        if(heap[j] > heap[i]){
            swap(heap[j], heap[i]);
            i = j;
            j = i * 2;
        }else
            break;
    }
}
int main() 
{
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> origin[i];
    for(int i = 1; i <= N; i++)
        cin >> target[i];
    memcpy(insert, origin, sizeof(origin));
    for(int i = 2; i < N; ++i){
        sort(insert+1, insert+1+i);
        if(equal(insert+1, insert+1+N, target+1)){
            cout << "Insertion Sort\n";
            ++i;
            sort(insert+1, insert+1+i);
            for(int j = 1; j <= N; ++j){
                cout << insert[j];
                if(j != N)
                    cout << " ";
            }
            return 0;     
        }
    }
    cout << "Heap Sort\n";
    memcpy(heap, origin, sizeof(origin));
    for(int i = N / 2; i >= 1; i--){
        downAdjust(i, N);
    }
    for(int i = N; i > 2; i--){
        swap(heap[i], heap[1]);
        downAdjust(1, i - 1);
        if(equal(heap+1, heap+1+N, target+1)){
            --i;
            swap(heap[i], heap[1]);
            downAdjust(1, i - 1);
            for(int j = 1; j <= N; ++j){
                cout << heap[j];
                if(j != N)
                    cout << " ";
            }
            break;
        }
    }
    return 0;
}