#include <iostream>

using namespace std;

const char DICT[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};

string radix(int a){
    if(a == 0)
        return "00";
    string res = "";
    while(a){
        res += DICT[a % 13];
        a /= 13;
    }
    if(res.size() == 1)
        res += '0';
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << '#' << radix(a) << radix(b) << radix(c);
    return 0;
}