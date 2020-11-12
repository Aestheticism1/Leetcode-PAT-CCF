#include <iostream>

using namespace std;

int main()
{
    string s, r;
    getline(cin, s);
    getline(cin, r);
    string res = "";
    for(auto x: s){
        if(r.find(x) == -1){
            res += x;
        }
    }
    cout << res;
    return 0;
}