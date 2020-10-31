#include <bits/stdc++.h>

using namespace std;

using gg = long long;
unordered_map<char, gg> um;  //存储字符和对应的基数

gg binarySearchF(gg left, gg right, function<bool(gg)> f) {
    while (left < right) {
        gg mid = (left + right) / 2;
        if (f(mid))
            right = mid;
        else
            left = mid + 1;
    }
    return left > right or not f(left) ? -1 : left;
}

gg rToDec(const string& r, gg R) {  //将R进制数转换成十进制数
    gg d = 0;
    for (auto i : r)
        d = d * R + um[i];
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s1, s2;
    gg tag, radix;
    cin >> s1 >> s2 >> tag >> radix;
    if (tag == 2)  //让s1作为指定了进制的数，s2作为要查找进制的数
        swap(s1, s2);
    for (gg i = 0; i < 36; ++i) {  //存储字符和对应的基数
        um.insert({i < 10 ? i + '0' : i - 10 + 'a', i});
    }
    gg n = rToDec(s1, radix);
    //找到s2中对应基数最大的字符，从而确定查找下限
    auto m = max_element(s2.begin(), s2.end(),
                         [](char c1, char c2) { return um[c1] < um[c2]; });
    gg left = um[*m] + 1;  //查找下限
    auto ans = binarySearchF(left, n + 1, [&s2, n](int a) {
        auto k = rToDec(s2, a);
        return k >= n or k < 0;  // k<0说明发生了数据溢出，这时也满足>=n的条件
    });
    //查找失败或查找到的第一个>=n的数不等于n，要输出Impossible
    ans == -1 or rToDec(s2, ans) != n ? cout << "Impossible" : cout << ans;
    return 0;
}