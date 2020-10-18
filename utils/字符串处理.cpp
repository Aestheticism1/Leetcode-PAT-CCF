#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// 根据某个字符分割字符串
void split(const string& s, vector<string>& tokens, char delim = ' ') {
    tokens.clear();
    auto string_find_first_not = [s, delim](size_t pos = 0) -> size_t {
        for (size_t i = pos; i < s.size(); i++) {
            if (s[i] != delim) return i;
        } 
        return string::npos;
    };
    size_t lastPos = string_find_first_not(0);
    size_t pos = s.find(delim, lastPos);
    while (lastPos != string::npos) {
        tokens.emplace_back(s.substr(lastPos, pos - lastPos));
        lastPos = string_find_first_not(pos);
        pos = s.find(delim, lastPos);
    }
}

int main()
{
    string s = "asd aw2 a213 asfb";
    vector<string> tokens;
    split(s, tokens);
    for(int i = 0; i < tokens.size(); i++)
        cout << tokens[i] << endl;
    return 0;
}