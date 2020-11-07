#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef long long ll;

string multiple(string s){
    string res = "";
    int add_one = 0;
    for(int i = s.size()-1; i >= 0; i--){
        int tmp = (s[i]-'0') * 2 + add_one;
        if(tmp >= 10){
            add_one = 1;
            tmp %= 10;
        }else{
            add_one = 0;
        }
        res += tmp + '0';
    }
    if(add_one)
        res += '1';
    return res;
}

int main()
{
    string s1, s2;
    cin >> s1;
    s2 = multiple(s1);
    reverse(s2.begin(), s2.end());

    map<int, int> a, b;
    for(auto x: s1){
        a[x-'0']++;
    }
    for(auto x: s2){
        b[x-'0']++;
    }
    bool flag = true;
    for(int i = 0; i < 10; ++i){
        if(a[i] != b[i])
            flag = false;
    }

    if(flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    cout << s2;
    return 0;
}