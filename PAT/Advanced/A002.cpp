#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<int, double> m;
    int num1, num2;
    cin >> num1;
    int exp;
    double coe;
    while(num1--){
        cin >> exp >> coe;
        m[exp] += coe;
    }
    
    cin >> num2;
    while(num2--){
        cin >> exp >> coe;
        m[exp] += coe;
        if(m[exp] == 0)
            m.erase(exp);
    }

    if(m.size() > 0)
        cout << m.size() << " ";
    else{
        cout << m.size();
        return 0;
    }
    
    map<int, double>::iterator x = --m.end();
    for(; x != m.begin(); --x)
        if(x->second != 0)
            cout << x->first << " " << setiosflags(ios::fixed) << setprecision(1) << x->second << " ";
    if(x->second != 0)
        cout << x->first << " " << setiosflags(ios::fixed) << setprecision(1) << x->second;

    return 0;
}