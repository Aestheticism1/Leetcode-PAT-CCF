#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    int N;
    cin >> a >> b >> N;
    unordered_map<string, string> nodes;
    while(N--){
        string addr, next;
        char c;
        cin >> addr >> c >> next;
        nodes[addr] = next;
    }

    unordered_map<string, bool> hash;
    while(a != "-1"){
        hash[a] = true;
        a = nodes[a];
    }
    while(b != "-1"){
        if(hash[b]){
            cout << b;
            return 0;
        }
        b = nodes[b];
    }
    cout << -1;
    return 0;
}