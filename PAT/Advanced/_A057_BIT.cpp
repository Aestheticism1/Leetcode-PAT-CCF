#include <iostream>
#include <vector>
#include <stack>
using namespace std;
auto lowbit = [](int x) { return x & (-x); };
vector<int> c(100005);
void update(int x, int v) {
    for (int i = x; i < c.size(); i += lowbit(i))
        c[i] += v;
}
int getSum(int x) {
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        sum += c[i];
    return sum; 
}
// 二分搜索
int search(int left, int right, int k) {
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (getSum(mid) >= k)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}
int main() {
    int n, a;
    stack<int> s;
    string command;
    cin >> n;
    while (cin >> command) {
        if (command == "Push") {
            cin >> a;
            s.push(a);
            update(a, 1);
        } else if (s.empty()) {
            cout << "Invalid\n";
        } else if (command == "Pop") {
            cout << s.top() << "\n";
            update(s.top(), -1);
            s.pop();
        } else if (command == "PeekMedian") {
            cout << search(1, c.size() - 1, (s.size() + 1) / 2) << "\n";
        }
    }
    return 0;
}