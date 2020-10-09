#include <iostream>
#include <cstring>
using namespace std;

const int L = 200;

/*
@brief multiplication of two big numbers
@param n1: multiplier
@param n2: multiplier
@return res
*/
string mul(string n1, string n2)
{
    string res;
    int a[L], b[L], r[L*2];
    fill(a, a+L, 0); fill(b, b+L, 0); fill(r, r+L*2, 0);
    int La = n1.size(), Lb = n2.size();
    int i, j;
    for(i = La - 1; i >= 0; i--){
        a[La-1-i] = n1[i] - '0';
    }

    for(i = Lb - 1; i >= 0; i--){
        b[Lb-1-i] = n2[i] - '0';
    }

    // *core*
    for(i = 0; i < La; i++)
        for(j = 0; j < Lb; j++)
            r[i + j] += a[i] * b[j];
    
    for(i = 0; i < L * 2; i++){
        if(r[i] >= 10){
            r[i + 1] += r[i] / 10;
            r[i] %= 10;
        }
    }

    i = L * 2 - 1;
    while(!r[i]) i--;
    if(i == 0) return "0";
    while(i >= 0){
        res += r[i--] + '0';
    }

    return res;
}

int main()
{
    string a, b;
    while(cin >> a >> b){
        cout << mul(a, b);
    }

    return 0;
}