#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct Record{
    int time, tag;
    Record(int ti, int ta) : time(ti), tag(ta){}
};
int main() 
{
    int N, K;
    cin >> N >> K;
    vector<vector<Record> > r(N);
    vector<vector<pair<int, int>>> duration(N);
    unordered_map<int, string> m1;
    unordered_map<string, int> m2;
    int cnt = 0;
    for(int i=0; i<N; ++i){
        string p, t;
        int h, m, s;
        cin >> p;
        int index;
        if(m2.find(p) != m2.end()){
            index = m2[p];
        }else{
            m1[cnt] = p;
            m2[p] = cnt;
            index = cnt;
            cnt++;
        }
        scanf("%d:%d:%d", &h, &m, &s);
        cin >> t;
        int time = h * 3600 + m * 60 + s;
        int tag = t[0] == 'i' ? 0 : 1;
        r[index].push_back(Record(time, tag));
    }
    int all_time[cnt];
    fill(all_time, all_time + cnt, 0);
    for(int i = 0; i < cnt; ++i){
        sort(r[i].begin(), r[i].end(), [](Record& a, Record& b){
            return a.time < b.time;
        });
        int len = r[i].size();
        for(int j = 0; j < len-1; ++j){
            if(r[i][j].tag == 0 && r[i][j+1].tag == 1){
                duration[i].push_back({r[i][j].time, r[i][j+1].time});
                all_time[i] += r[i][j+1].time - r[i][j].time;
                ++j;
            }
        }
    }
    vector<string> longest;
    int longest_time = -1;
    for(int i = 0; i < cnt; ++i){
        if(all_time[i] > longest_time){
            longest_time = all_time[i];
            longest.clear();
            longest.push_back(m1[i]);
        }else if(all_time[i] == longest_time){
            longest.push_back(m1[i]);
        }
    }
    while(K--){
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);
        int time = h * 3600+ m * 60 + s;
        int res = 0;
        for(int i = 0; i < duration.size(); ++i){
            for(auto x: duration[i]){
                if(x.first <= time && time < x.second){
                    res++;
                    break;
                }
            }
        }
        printf("%d\n", res);
    }
    sort(longest.begin(), longest.end());
    for(auto x: longest)
        printf("%s ", x.c_str());
    printf("%02d:%02d:%02d", longest_time / 3600, longest_time % 3600 / 60, longest_time % 3600 % 60);
    return 0;
}