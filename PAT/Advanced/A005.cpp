#include <bits/stdc++.h>

using namespace std;

const vector<string> NUMBER_STRING = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}; 

int main()
{
    string N;
    cin >> N;
    long long res = 0;
    for(auto x: N){
        res += x-'0'; 
    }

    string s = to_string(res);
    int i;
    for(i = 0; i < (int)s.length()-1; i++){
        cout << NUMBER_STRING[s[i]-'0'] << " ";
    }
    cout << NUMBER_STRING[s[i]-'0'];
    return 0;
}