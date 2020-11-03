#include <iostream>
#include <string>
#include <unordered_map>
#include <array>
#include <vector>

using namespace std;

typedef pair<int, float> StudentScore;

const string INT_TO_CHAR = "ACME";
unordered_map<int, array<int, 4>> ranks;
vector<vector<StudentScore>> grades(4);

void getRank(vector<StudentScore>& grade, int index){
    ranks[grade[0].first][index] = 1;
    for(int i = 1; i < (int)grade.size(); i++){
        if(grade[i].second != grade[i-1].second)
            ranks[grade[i].first][index] = i + 1;
        else
            ranks[grade[i].first][index] = ranks[grade[i-1].first][index];
    } 
}

int main()
{
    int N, M;
    cin >> N >> M;
    while(N--){
        int id;
        float c, m, e;
        cin >> id >> c >> m >> e;
        grades[0].push_back({id, (c+m+e)/3.0});
        grades[1].push_back({id, c});
        grades[2].push_back({id, m});
        grades[3].push_back({id, e});
    }

    for(int i = 0; i < 4; i++)
        sort(grades[i].begin(), grades[i].end(), [](const StudentScore& s1, const StudentScore& s2){
            return s1.second > s2.second;
        });
    
    for(int i = 0; i < 4; i++)
        getRank(grades[i], i);

    while(M--){
        int q;
        cin >> q;
        if(ranks.find(q) == ranks.end()){
            cout << "N/A" << endl;
        }else{
            auto x = min_element(ranks[q].begin(), ranks[q].end());
            cout << *x << " " << INT_TO_CHAR[x-ranks[q].begin()] << endl;
        }
    }

    return 0;
}