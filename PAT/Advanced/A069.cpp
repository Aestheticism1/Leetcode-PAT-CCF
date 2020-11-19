#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    do{
        string s = to_string(n);
        while(s.size() < 4)
            s.push_back('0');
        sort(s.begin(), s.end(), greater<char>());
        int a = stoi(s);
        sort(s.begin(), s.end());
        int b = stoi(s);
        n = a - b;
        printf("%04d - %04d = %04d\n", a, b, n);
    }while(n != 0 && n != 6174);
    return 0;
}