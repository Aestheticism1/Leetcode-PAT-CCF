#include <iostream>

using namespace std;

struct Mooncake{
    double amount, profit;
};

int main()
{
    int N, D;
    cin >> N >> D;
    Mooncake m[N];
    for(int i = 0; i < N; ++i)
        cin >> m[i].amount;
    for(int i = 0; i < N; ++i)
        cin >> m[i].profit;
    sort(m, m+N, [](const Mooncake &a, const Mooncake &b){
        return (a.profit*1.0/a.amount) > (b.profit*1.0/b.amount);
    });
    double p=0.0;
    for(int i = 0; i < N; ++i){
        if(D < m[i].amount){
            p += m[i].profit * 1.0 / m[i].amount * D;
            break;
        }else{
            D -= m[i].amount;
            p += m[i].profit;
        }
    }
    printf("%.2lf", p);
    return 0;
}