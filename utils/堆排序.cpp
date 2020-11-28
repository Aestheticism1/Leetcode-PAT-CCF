#include <iostream>

using namespace std;

const int maxn = 100;
int heap[maxn], n = 10;

// 对heap数组在[low, high]范围进行向下调整
// low为欲调整结点的数组下标
void downAdjust(int low, int high){
    int i = low, j = i * 2;
    while(j <= high){
        if(j + 1 <= high && heap[j + 1] > heap[j])
            j = j + 1;
        if(heap[j] > heap[i]){
            swap(heap[j], heap[i]);
            i = j;
            j = i * 2;
        }
        else
            break;
    }
}

void createHeap(){
    //完全二叉树的叶子结点个数为n/2个，因此数组下标在[1, n/2]范围内的结点都是非叶子结点
    //倒着枚举非叶子结点
    for(int i = n / 2; i >= 1; i--){
        downAdjust(i, n);
    }
}

void deleteTop(){
    heap[1] = heap[n--];
    downAdjust(1, n);
}

// 对heap数组在[low, high]范围进行向上调整
// high表示欲调整结点的数组下标，low一般为1
// 添加元素的时候才要用到该函数
void upAdjust(int low, int high){
    int i = high, j = i / 2;
    while(j >= low){
        if(heap[j] < heap[i]){
            swap(heap[j], heap[i]);
            i = j;
            j = i / 2;
        }else
            break;
    }
}

void insert(int x){
    heap[++n] = x;
    upAdjust(1, n);
}

// 堆排序（大顶堆）
void heapSort(){
    createHeap();
    // 建堆完毕之后最大值在堆顶，交换堆顶(1)和堆末元素(i)，即把最大值固定到最后
    // 再调整[1, i-1]
    for(int i = n; i > 1; i--){
        swap(heap[1], heap[i]);
        downAdjust(1, i - 1);
    }
}

int main()
{
    for(int i = 1; i <= n; ++i)
        cin >> heap[i];
    heapSort();
    for(int i = 1; i <= n; ++i)
        cout << heap[i] << " ";
    return 0;
}