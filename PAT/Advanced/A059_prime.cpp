#include <iostream>
#include <vector>

using namespace std;

const int L = 1e+5;
vector<int> primes;
bool p[L];
void getPrime(){
    fill(p, p+L, true);
    for(int i = 2; i < L; i++){
        if(p[i]){
            primes.push_back(i);
            for(int j = i+i; j < L; j += i){
                p[j] = false;
            }
        }
    }
}

int main()
{
    getPrime();
    int N;
    cin >> N;
    int NC = N;
    if(N == 1){
        printf("1=1");
        return 0;
    }
    int cnt;
    vector<pair<int, int>> res;
    for(int i = 0; i < primes.size(); ++i){
        cnt = 0;
        while(N % primes[i] == 0){
            N /= primes[i];
            cnt++;
        }
        if(cnt)
            res.push_back({primes[i], cnt});
        if(N == 1)
            break;
    }
    printf("%d=", NC);
    for(int i = 0; i < res.size(); ++i){
        printf("%d", res[i].first);
        if(res[i].second > 1)
            printf("^%d", res[i].second);
        if(i != res.size() - 1)
            printf("*");
    }
}