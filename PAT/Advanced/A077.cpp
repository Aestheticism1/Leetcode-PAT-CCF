#include <iostream>

using namespace std;

const int L = 105;

int main()
{
    int N;
    cin >> N;
    getchar();
    string A[L];
    string res = "";
    int len = INT_MAX;
    for(int i = 0; i < N; ++i){
        getline(cin, A[i]);
        len = min(len, (int)A[i].length());
    }
    bool flag;
    for(int i = 0; i < len; ++i){
        flag = true;
        for(int j = 1; j < N; ++j){
            if(A[j][A[j].length() - 1 - i] != A[j-1][A[j-1].length() - 1 - i])
                flag = false;
        }
        if(flag)
            res += A[0][A[0].length() - 1 - i];
        else
            break;
    }
    if(res == "")
        printf("nai");
    else{
        reverse(res.begin(), res.end());
        printf("%s", res.c_str());
    }
    return 0;
}