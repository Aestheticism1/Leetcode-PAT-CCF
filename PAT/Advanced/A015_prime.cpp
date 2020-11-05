#include <iostream>
#include <math.h>

using namespace std;

const int L = 1e+5;
bool prime[L];

//埃氏筛法求素数表
void getPrime(){
    fill(prime+2, prime+L, true);
    for(int i = 2; i < L; i++){
        if(prime[i]){
            for(int j = i + i; j < L; j += i){
                prime[j] = false;
            }
        }
    }
}

//将给定的数在给定进制下翻转之后按十进制数返回
int radix_reverse(int n, int radix){
    int res = 0;
    while(n){
        res = res * radix + n % radix;
        n /= radix;
    }
    return res;
}

bool isPrime(int n){
    if(n == 1)
        return false;
    
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main()
{
    getPrime();
    int n;
    while(cin >> n && n > 0){
        int radix;
        cin >> radix;
        int re = radix_reverse(n, radix);

        if(prime[n] && prime[re])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}