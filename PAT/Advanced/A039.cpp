#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, vector<int>> res;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    while(K--){
        int index, num;
        cin >> index >> num;
        while(num--){
            string name;
            cin >> name;
            res[name].push_back(index);
        }
    }
    while(N--){
        string q;
        cin >> q;
        cout << q << " " << res[q].size();
        if(res[q].size() > 0){
            sort(res[q].begin(), res[q].end());
            for(auto x: res[q])
                cout << " " << x;
        }
        if(N != 0){
            cout << endl;
        }
    }
    return 0;
}