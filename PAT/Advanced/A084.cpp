#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    unordered_set<char> c;
    for(int i = 0; i < b.size(); ++i){
        if(b[i] >= 'a' && b[i] <= 'z')
            b[i] -= 32;
        if(b[i] != '-')
            c.insert(b[i]);
    }
    transform(a.begin(), a.end(), a.begin(), ::toupper);
    for(int i = 0; i < a.size(); ++i){
        if(a[i] != '-' && c.find(a[i]) == c.end()){
            cout << a[i];
            c.insert(a[i]);
        }
    }
    return 0;
}