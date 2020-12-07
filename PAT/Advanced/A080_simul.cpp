#include <iostream>
#include <vector>

using namespace std;

const int L = 4e4+5;

struct Stu{
    int id=0, ge=0, gi=0, total=0, rank=1;
    vector<int> prefer;
}stu[L];

bool cmp(Stu& a, Stu& b){
    return a.total != b.total ? a.total > b.total : a.ge > b.ge;
}

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    int quota[M];
    int lastRank[M];
    vector<int> res[M];
    for(int i = 0; i < M; ++i)
        cin >> quota[i];
    
    for(int i = 0; i < N; ++i){
        cin >> stu[i].ge >> stu[i].gi;
        stu[i].id = i;
        stu[i].total = (stu[i].ge + stu[i].gi)/2;
        int tmp;
        for(int j = 0; j < K; ++j){
            cin >> tmp;
            stu[i].prefer.push_back(tmp);            
        }
    }
    sort(stu, stu+N, cmp);
    for(int i = 1; i < N; ++i)
        stu[i].rank = stu[i].total == stu[i-1].total && stu[i].ge == stu[i-1].ge ? stu[i-1].rank : i+1;
    
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < K; ++j){
            int school = stu[i].prefer[j];
            if(quota[school] > 0 || stu[i].rank == lastRank[school]){
                quota[school]--;
                res[school].push_back(stu[i].id);
                lastRank[school] = stu[i].rank;
                break;
            }
        }
    }
    for(int i = 0; i < M; ++i){
        if(res[i].size() > 0){
            sort(res[i].begin(), res[i].end());
            for(int j = 0; j < res[i].size(); ++j){
                cout << res[i][j];
                if(j != res[i].size() - 1){
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}