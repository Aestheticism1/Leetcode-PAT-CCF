#include <iostream>
#include <vector>

using namespace std;

string name[40005];

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> courses[K+1];
    for(int i = 0; i < N; ++i){
        int C, tmp;
        cin >> name[i] >> C;
        while(C--){
            cin >> tmp;
            courses[tmp].push_back(i);
        }
    }
    for(int i = 1; i <= K; i++){
        cout << i << " " << courses[i].size() << endl;
        sort(courses[i].begin(), courses[i].end(), [](int a, int b){
            return name[a] < name[b];
        });
        // 这样写最后一个测试用例会超时
        // for(auto x: courses[i])
        //     cout << name[x] << endl;
        for(int j = 0; j < courses[i].size(); ++j)
            puts(name[courses[i][j]].c_str());
    }
    return 0;
}