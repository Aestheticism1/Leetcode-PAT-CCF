#include <iostream>
#include <map>

using namespace std;

int main()
{  
    string s;
    getline(cin, s);
    map<string, int> m;
    
    string tmp = "";
    for(int i = 0; i < s.length(); ++i){
        if(s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
        
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            tmp += s[i];
        }else if(tmp.length() != 0){
            m[tmp]++;
            tmp.clear();
        }
    }

    if(tmp.length() != 0){
        m[tmp]++;
        tmp.clear();
    }

    auto max = m.begin();
    for(auto x = ++m.begin(); x != m.end(); ++x){
        if(x->second > max->second){
            max = x;
        }
    }
    cout << max->first << " " << max->second;

    return 0;
}