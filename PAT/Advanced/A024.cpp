#include <iostream>

using namespace std;

bool is_palindromic(string s){
    int len = s.size();
    bool flag = true;
    for(int i = 0; i < len / 2; i++)
        if(s[i] != s[len-1-i])
            flag = false;
    return flag;
}

string add(string s1){
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    int num = 0;
    string res = "";
    for(int i = 0; i < s1.size(); i++){
        int tmp = (s1[i]-'0') + (s2[i]-'0') + num;
        if(tmp >= 10){
            tmp %= 10;
            num = 1;
        }else{
            num = 0;
        }
        res += tmp + '0';
    }
    if(num)
        res += '1';
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string N;
    int K;
    cin >> N >> K;
    
    if(is_palindromic(N)){
        cout << N << endl << 0;
        return 0;
    }
    
    for(int i = 1; i <= K; i++){
        N = add(N);
        if(is_palindromic(N) || i == K){
            cout << N << endl << i;
            break;
        }
    }
    return 0;
}