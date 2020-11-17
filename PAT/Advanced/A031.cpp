#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int len = s.size();
    int n = 2;
    int n2 = len + 2 - n * 2;
    
    int resn, resn2;
    while(n2 >= n){
        resn = n;
        resn2 = n2;
        ++n;
        n2 = len + 2 - n * 2;
    }
    
    for(int i = 0; i < resn; ++i){
        if(i != resn - 1){
            cout << s[i];
            for(int j = 0; j < resn2 - 2; ++j)
                cout << " ";
            cout << s[len - 1 - i] << endl;
        }else{
            for(int k = 0; k < resn2; ++k)
                cout << s[i + k];
        }
    }
    return 0;
}