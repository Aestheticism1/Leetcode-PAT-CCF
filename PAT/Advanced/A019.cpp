#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<string> nn;

void transfer(ll n, ll base){
    while(n != 0){
        nn.push_back(to_string(n % base));
        n /= base;
    };
}

int main()
{
    ll n, b;
    cin >> n >> b;
    transfer(n, b);
    bool flag = true;
    int len = nn.size();
    for(int i = 0; i < len / 2; i++)
        if(nn[i] != nn[len - 1 - i])
            flag = false;
    
    if(flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    for(int i = nn.size() - 1; i >= 0; i--){
        if(i != 0)
            cout << nn[i] << " ";
        else
            cout << nn[i];
    }
    return 0;
}