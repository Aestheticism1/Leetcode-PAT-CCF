#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    
    int a = s[0] == '+' ? 1 : 0;
    string s1 = "";
    int i = 1;
    while(s[i] != 'E'){
        if(s[i] != '.')
            s1 += s[i];
        i++;
    }
    int j = 0;
    for(; j < s1.length() && s1[j] == '0'; ++j);

    ++i;
    int b = s[i++] == '+' ? 1 : 0;
    string s2 = "";
    while(i < s.length()){
        s2 += s[i++];
    }
    int c = stoi(s2);
    if(b){
        if(c > s1.length()-1){
            int len = c - s1.length() + 1;
            for(int i = 0; i < len; ++i)
                s1 += "0";
            if(j > 0){
                s1 = s1.substr(j, s1.length() - j);
            }
        }else if(c != s1.length() - 1){
            if(j > 0 && c > 0){
                j = c > j ? j : c;
                s1 = s1.substr(j, s1.length() - j);
            }
            s1.insert(1+c-j, ".");
        }
    }else{
        for(int i = 0; i < c; ++i)
            s1 = "0" + s1;
        s1.insert(1, ".");
    }
    printf("%s%s", a ? "" : "-", s1.c_str());
    return 0;
}