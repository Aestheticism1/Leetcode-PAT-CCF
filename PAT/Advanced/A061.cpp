#include <iostream>
#include <unordered_map>

using namespace std;

const string A[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main()
{
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    unordered_map<char, int> hash;
    for(int i = 0; i < 10; ++i)
        hash[i+'0'] = i;
    for(int i = 0; i < 14; ++i)
        hash['A'+i] = 10+i;

    int day, hour, minute, cnt = 0;
    for(int i = 0; i < min(s1.length(), s2.length()); ++i){
        if(s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G' && cnt == 0){
            day = s1[i] - 'A';
            ++cnt; ++i;
        }
        if(s1[i] == s2[i] && hash.find(s1[i]) != hash.end() && cnt == 1){
            hour = hash[s1[i]];
            break;
        }
    }

    for(int i = 0; i < min(s3.length(), s4.length()); ++i){
        if(s3[i] == s4[i] && ((s3[i] >= 'a' && s3[i] <= 'z') || (s3[i] >= 'A' && s3[i] <= 'Z'))){
            minute = i;
            break;
        }
    }

    printf("%s %02d:%02d", A[day].c_str(), hour, minute);
    
    return 0;
}