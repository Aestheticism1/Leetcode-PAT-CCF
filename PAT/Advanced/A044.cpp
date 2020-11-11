#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int a[N];
    for(int i = 0; i < N; ++i)
        cin >> a[i];
    
    int min = INT_MAX;
    vector<pair<int, int>> res;
    for(int i = 0; i < N; ++i){
        int sum = 0;
        int j = i;
        while(j < N && sum < M){
            sum += a[j];
            j++;
        }
        if(sum < M)
            break;
        if(sum < min){
            res.clear();
            res.push_back({i+1, j});
            min = sum;
        }else if(sum == min){
            res.push_back({i+1, j});
        }
    }
    for(int i = 0; i < res.size(); ++i){
        if(i != res.size()-1)
            cout << res[i].first << '-' << res[i].second << endl;
        else
            cout << res[i].first << '-' << res[i].second;
    }
    return 0;
}