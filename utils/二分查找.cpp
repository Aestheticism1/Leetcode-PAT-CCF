#include <iostream>
#include <algorithm>

using namespace std;

int a[100]= {4,10,11,30,69,70,96,100};

// binary_search 判断存在
// lower_bound 找第一个>=的下标
// upper_bound 找第一个>的下标
// lower_bound和upper_bound在[first, last)查找，如果所有元素都小于x，返回last
void stl(){
    int b=binary_search(a,a+8,4);   //查找成功，返回1
    cout<<"在数组中查找元素4，结果为："<<b<<endl;
    int c=binary_search(a,a+8,40);  //查找失败，返回0
    cout<<"在数组中查找元素40，结果为："<<c<<endl;
    int d=lower_bound(a,a+8,10)-a;
    cout<<"在数组中查找第一个大于等于10的元素位置，结果为："<<d<<endl;
    int e=lower_bound(a,a+8,101)-a;  // 8
    cout<<"在数组中查找第一个大于等于101的元素位置，结果为："<<e<<endl;
    int f=upper_bound(a,a+8,10)-a;
    cout<<"在数组中查找第一个大于10的元素位置，结果为："<<f<<endl;
    int g=upper_bound(a,a+9,101)-a;  // 9
    cout<<"在数组中查找第一个大于101的元素位置，结果为："<<g<<endl;
}

int binarySearch(int x, int n)
{
    int left =0;
    int right=n-1;
    while(left<=right)
    {
        int mid =(left+right)/2;
        if(x==a[mid])
            return mid;
        if(x>a[mid])
            left=mid+1;
        else
            right =mid-1;
    }
    return -1;//未找到x
}

//二分搜索递归实现
int recurisonBinarySearch(int left, int right, int x)
{
    if(left>right) return -1;
    int mid =(left+right)/2;
    if(x==a[mid]) return mid;
    if(x>a[mid])
        return recurisonBinarySearch(mid+1,right,x);
    else
        return recurisonBinarySearch(left,mid-1,x);
}

int main()
{
    stl();

    int x;
    int ans1,ans2;
    cin >> x;
    ans1=binarySearch(x, 8);
    ans2=recurisonBinarySearch(0, 7, x);
    cout << ans1 << " " << ans2 << endl;
    return 0;
}