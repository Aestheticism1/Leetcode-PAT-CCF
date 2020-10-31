#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int last = 0;
    int res = 0;
    while(N--){
        int t;
        cin >> t;
        if(t > last){
            res += 6 * (t - last) + 5;
            last = t;
        }else if (t < last){
            res += 4 * (last - t) + 5;
            last = t;
        }else{
            res += 5;
        }
    }
    cout << res;
    return 0;
}