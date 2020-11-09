#include <iostream>
#include <vector>
#include <regex>

using namespace std;

string check(const string pwd){
    string s = pwd;
    s = regex_replace(s, regex("1"), "@");
    s = regex_replace(s, regex("0"), "%");
    s = regex_replace(s, regex("l"), "L");
    s = regex_replace(s, regex("O"), "o");
    return s;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<pair<string, string>> res;
    for(int i = 0; i < N; ++i){
        string name, pwd;
        cin >> name >> pwd;
        string ss = check(pwd);
        if(ss != pwd){
            res.push_back({name, ss});
        }
    }
    if(res.size() == 0){
        if(N > 1)
            cout << "There are " << N << " accounts and no account is modified";
        else
            cout << "There is " << N << " account and no account is modified";
    }else{
        cout << res.size() << endl;
        for(int i = 0; i < res.size(); i++){
            if(i != res.size() - 1)
                cout << res[i].first << " " << res[i].second << endl;
            else 
                cout << res[i].first << " " << res[i].second;
        }
    }
    return 0;
}