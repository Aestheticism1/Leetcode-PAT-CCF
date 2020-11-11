#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    string s = "SHCD";
    vector<string> origin(55);
    for(int i = 0; i < 4; i++){
        for(int j = 1; j <= 13; j++){
            origin[i*13+j] = s[i] + to_string(j);
        }
    }
    origin[53] = "J1";
    origin[54] = "J2";
    
    int K;
    cin >> K;
    unordered_map<int, int> hash;
    for(int i = 1; i <= 54; ++i){
        int tmp;
        cin >> tmp;
        hash[tmp] = i;
    }
    vector<string> res(55);
    while(K--){
        for(int i = 1; i <= 54; ++i){
            res[i] = origin[hash[i]];
        }
        origin = res;
    }
    for(int i = 1; i <= 53; ++i)
        cout << res[i] << " ";
    cout << res[54];
    return 0;
}