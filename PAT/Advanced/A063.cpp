#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    set<int> A[52];
    for(int i = 1; i <= N; ++i){
        int num;
        cin >> num;
        while(num--){
            int tmp;
            cin >> tmp;
            A[i].insert(tmp);
        }
    }
    int K;
    cin >> K;
    while(K--){
        int set1, set2;
        cin >> set1 >> set2;
        vector<int> tmp;
        set_intersection(A[set1].begin(), A[set1].end(), A[set2].begin(), A[set2].end(), back_inserter(tmp));
        printf("%.1f%%", tmp.size() * 100.0 / (A[set1].size() + A[set2].size() - tmp.size()));
        if(K != 0)
            printf("\n");
    }
    return 0; 
}