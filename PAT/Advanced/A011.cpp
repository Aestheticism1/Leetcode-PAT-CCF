#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Team{
    char poss;
    float profit;
    Team(char po, float pro): poss(po), profit(pro){}
};

bool cmp(const Team a, const Team b){
    return a.profit > b.profit;
}

int main()
{    
    vector<vector<Team>> odds(3);
    float W, T, L;
    for(int i = 0; i < 3; i++){
        cin >> W >> T >> L;
        odds[i].push_back(Team('W', W));
        odds[i].push_back(Team('T', T));
        odds[i].push_back(Team('L', L));
        sort(odds[i].begin(), odds[i].end(), cmp);
    }

    float res = (odds[0][0].profit * odds[1][0].profit * odds[2][0].profit * 0.65 - 1) * 2.0;
    cout << odds[0][0].poss << " " << odds[1][0].poss << " " << odds[2][0].poss << " " << setiosflags(ios::fixed) << setprecision(2) << res; 
    return 0;
}