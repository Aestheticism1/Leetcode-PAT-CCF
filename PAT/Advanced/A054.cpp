#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;
    int tmp;
    unordered_map<int, int> hash;
    int half = M * N / 2;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            cin >> tmp;
            hash[tmp]++;
            if(hash[tmp] > half){
                cout << tmp;
                return 0;
            }
        }
    }
    return 0;
}