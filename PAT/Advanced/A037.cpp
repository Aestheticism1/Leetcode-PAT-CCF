#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    int NC;
    cin >> NC;
    vector<ll> coupon_p, coupon_n;
    while (NC--){
        ll tmp;
        cin >> tmp;
        if(tmp > 0)
            coupon_p.push_back(tmp);
        if(tmp < 0)
            coupon_n.push_back(tmp);
    }
    int NP;
    cin >> NP;
    vector<ll> product_p, product_n;
    while (NP--){
        ll tmp;
        cin >> tmp;
        if(tmp > 0)
            product_p.push_back(tmp);
        if(tmp < 0)
            product_n.push_back(tmp);
    }
    sort(coupon_p.begin(), coupon_p.end(), greater<int>());
    sort(coupon_n.begin(), coupon_n.end());
    sort(product_p.begin(), product_p.end(), greater<int>());
    sort(product_n.begin(), product_n.end());

    ll sum = 0;
    int len = min(coupon_p.size(), product_p.size());
    for(int i = 0; i < len; i++)
        sum += coupon_p[i] * product_p[i];
    
    len = min(coupon_n.size(), product_n.size());
    for(int i = 0; i < len; i++)
        sum += coupon_n[i] * product_n[i];

    cout << sum;

    return 0;
}