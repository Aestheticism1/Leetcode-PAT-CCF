#include <iostream>
#include <vector>

using namespace std;

// 快速排序
void Qsort(vector<int>& a, int low, int high){
    if(low >= high)
        return ;
    int first = low;
    int last = high;
    int key = a[first];
    while(first < last){
        while(first < last && a[last] >= key)
            --last;
        a[first] = a[last];
        while(first < last && a[first] <= key)
            ++first;
        a[last] = a[first];
    }
    a[first] = key;
    Qsort(a, low, first-1);
    Qsort(a, first+1, high);
}

int main()
{
    vector<int> a{2, 1, 4, 3, 5, 2, 6};
    Qsort(a, 0, a.size()-1);
    for(auto x: a)
        cout << x << " ";
    return 0;
}