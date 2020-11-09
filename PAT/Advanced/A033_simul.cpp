#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const int L = 2e3+5;
bool mark[L];
unordered_map<string, pair<int, int> > people;
unordered_map<int, string> index_to_person;
vector<vector<int>> graph(L);

void dfs(int v, vector<int>& gang){
    mark[v] = true;
    gang.push_back(v);
    for(auto x: graph[v]){
        if(!mark[x])
            dfs(x, gang);
    }
}

int total(vector<int> g){
    int res = 0;
    for(auto x: g){
        res += people[index_to_person[x]].second;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    int cnt = 0;
    while(N--){
        string a, b;
        int t;
        cin >> a >> b >> t;
        if(people.find(a) == people.end()){
            index_to_person[cnt] = a;
            people[a] = make_pair(cnt++, t);
        }else{
            people[a].second += t;
        }
        if(people.find(b) == people.end()){
            index_to_person[cnt] = b;
            people[b] = make_pair(cnt++, t);
        }else{
            people[b].second += t;
        }
        graph[people[a].first].push_back(people[b].first);
        graph[people[b].first].push_back(people[a].first);
    }
    int n = people.size();
    vector<vector<int> > res;
    for(int i = 0; i < n; i++){
        vector<int> gang;
        if(!mark[i]){
            dfs(i, gang);
        }
        if(gang.size() >= 3 && total(gang) > K*2)
            res.push_back(gang);
    }

    vector<pair<string, int> > heads;
    if(res.size() == 0)
        cout << 0;
    else{
        cout << res.size() << endl;
        for(auto g: res){
            int max = INT_MIN;
            string head;
            for(auto p: g){
                string name = index_to_person[p];
                if(people[name].second > max){
                    max = people[name].second;
                    head = name;
                }
            }
            heads.push_back({head, g.size()});
        }
        sort(heads.begin(), heads.end());
        for(int i = 0; i < heads.size(); i++){
            if(i != heads.size()-1)
                cout << heads[i].first << " " << heads[i].second << endl;
            else
                cout << heads[i].first << " " << heads[i].second;
        }
    }
    
    return 0;
}