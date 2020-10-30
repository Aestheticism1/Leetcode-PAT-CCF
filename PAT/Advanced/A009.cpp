#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

int main()
{
    vector<pair<int, float>> A;
    vector<pair<int, float>> B;
    map<int, float, greater<int>> m;
    int k;
    cin >> k;
    while(k--){
        int n;
        float an;
        cin >> n >> an;
        A.push_back(make_pair(n, an));
    } 
    cin >> k;
    while(k--){
        int n;
        float an;
        cin >> n >> an;
        B.push_back(make_pair(n, an));   
    }

    for(auto a: A){
        for(auto b: B){
            m[a.first + b.first] += a.second * b.second;
            if(m[a.first + b.first] == 0)
                m.erase(a.first + b.first);
        }
    }
    
    if(m.size() == 0){
        cout << m.size();
        return 0;
    }
    
    cout << m.size() << " ";
    for(auto x = m.begin(); x != --m.end(); ++x){
        if(x->second != 0){
            cout << x->first << " " << setiosflags(ios::fixed) << setprecision(1) << x->second << " ";
        }
    }
    auto x = --m.end();
    cout << x->first << " " << setiosflags(ios::fixed) << setprecision(1) << x->second;
    
    return 0;
}