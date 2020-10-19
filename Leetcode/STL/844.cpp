#include <iostream>

using namespace std;

// 双指针
// 空间复杂度：O(1)
// 时间复杂度：O(N+M)
bool backspaceCompare_o1(string S, string T){
    int i = S.length() - 1, j = T.length() - 1;
    int skipS = 0, skipT = 0;

    while (i >= 0 || j >= 0) {
        while (i >= 0) {
            if (S[i] == '#') {
                skipS++, i--;
            } else if (skipS > 0) {
                skipS--, i--;
            } else {
                break;
            }
        }
        while (j >= 0) {
            if (T[j] == '#') {
                skipT++, j--;
            } else if (skipT > 0) {
                skipT--, j--;
            } else {
                break;
            }
        }
        if (i >= 0 && j >= 0) {
            if (S[i] != T[j]) {
                return false;
            }
        } else {
            if (i >= 0 || j >= 0) {
                return false;
            }
        }
        i--, j--;
    }
    return true;
}

// 栈
// 空间复杂度：O(N+M)
// 时间复杂度：O(N+M)
string build(string str) {
    string ret;
    for (char ch : str) {
        if (ch != '#') {
            ret.push_back(ch);
        } else if (!ret.empty()) {
            ret.pop_back();
        }
    }
    return ret;
}

bool backspaceCompare(string S, string T) {
    return build(S) == build(T);
}

int main(){
    string S, T;
    while(cin >> S >> T)
        cout << backspaceCompare_o1(S, T) << endl;
}