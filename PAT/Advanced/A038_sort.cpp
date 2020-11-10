#include <iostream>
#include <vector>

using namespace std;

bool cmp(string& a, string& b){
    return a + b < b + a;
}

int main()
{
    int N;
    cin >> N;
    string segments[N], s = "";
    for(int i = 0; i < N; ++i)
        cin >> segments[i];
    
    sort(segments, segments + N, cmp);
    for(int i = 0; i < N; ++i)
		s += segments[i];
    int i = 0;
    while(i < s.size() && s[i] == '0')
        i++;
    
    if(i == s.size())
        cout << '0';
    else
        while(i < s.size())
            cout << s[i++];
    return 0;
}