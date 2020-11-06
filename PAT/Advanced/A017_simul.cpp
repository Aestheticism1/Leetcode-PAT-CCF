#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e5;
const int OPEN = 3600 * 8;
const int CLOSE = 3600 * 17;

vector<pair<int, int>> customer; // pair<到达时间，办理时间>
int n, k;

void solve()
{
    vector<int> window(k, OPEN); // 每个窗口服务完上个客户的时间
    double waitTime = 0;
    for (int i = 0; i < customer.size(); i++)
    {
        int arr = customer[i].first, pro = customer[i].second;
        auto it = min_element(window.begin(), window.end()); // 选择最先完成服务的窗口
        if (arr < *it) // 到来时还有人在处理
        {
            waitTime += *it - arr; // 先等待
            *it += pro;            // 再办理
        }
        else
            *it = arr + pro; // 无人直接办理
    }
    printf("%.1lf", waitTime / 60 / customer.size());
}

int main()
{
    cin >> n >> k;
    while (n--)
    {
        int h, m, s, t, pro;
        scanf("%d:%d:%d %d", &h, &m, &s, &pro);
        pro = min(pro, 60); // 每个人办理时间不超过一小时
        t = h * 3600 + m * 60 + s;
        if (t <= CLOSE)
            customer.push_back({t, pro * 60});
    }
    sort(customer.begin(), customer.end()); // 将客户按到来时间从小到大排序
    solve();
    return 0;
}
