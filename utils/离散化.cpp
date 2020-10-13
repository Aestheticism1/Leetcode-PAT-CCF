#include <iostream>

using namespace std;
const int N = 1e5+7;
int a[N], t[N];

void show(int *a, int n){
    for(int i=1; i<=n; i++)
        cout << a[i] << " ";
    cout << endl;
}

/* 离散化 */
// 当有些数据因为本身很大或者类型不支持，自身无法作为数组的下标来方便地处理，
// 而影响最终结果的只有元素之间的相对大小关系时，我们可以将原来的数据按照从小到大编号来处理问题，即离散化
// 例：输入[10,12362,4213412,1,116] 输出[2,4,5,1,3]

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        t[i] = a[i];
    }
    sort(t+1, t+1+n);
    int m = unique(t+1, t+1+n) - t - 1;  // 去重
    for(int i=1; i<=n; i++){
        a[i] = lower_bound(t+1, t+1+m, a[i]) - t;  // lower_bound在t中找第一个>=a[i]的下标
    }

    show(a, n);

    /* 对vector进行离散化 */
    // vector<int> a, b;   // b是a的一个副本
    // sort(b.begin(), b.end());
    // b.erase(unique(b.begin(), b.end()), b.end());
    // for (int i = 0; i < n; ++i)
    //     a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();

    return 0;
}