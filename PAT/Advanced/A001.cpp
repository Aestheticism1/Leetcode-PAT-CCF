#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    while(cin >> a >> b){
        int sum = a + b;
        if(sum > -1000 && sum < 1000){
            cout << sum << endl;
        }else{
            string c = to_string(sum);
            int end = sum < 0 ? 2 : 1;
            for(int i = c.length() - 3; i >= end; i-=3){
                c = c.insert(i, 1, ',');
            }
            cout << c << endl;
        }
    }
    return 0;
}