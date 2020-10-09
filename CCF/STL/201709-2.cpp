#include <iostream>
#include <queue>

using namespace std;

struct Key{
    int num;    // 钥匙编号
    int time;   // 当前时间
    bool borrow;    // true借 false还
    Key(int n, int t, bool b):num(n),time(t),borrow(b){}
    // 重载<运算符，优先级队列默认以最大元素为队首
    bool operator < (const Key& k) const {
        if(this->time != k.time)            //时刻最早的优先级最高
            return this->time > k.time;
        else if(this->borrow != k.borrow)   //同一时刻先还后借
            return this->borrow && !k.borrow;
        else                                //同一时刻同一操作下编号越小优先级越高
            return this->num > k.num;
    }
};

priority_queue<Key> pq;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n+1], i;
    for(i = 0; i < n+1; i++)
        a[i] = i;

    int w, s, c;
    while(k--){
        cin >> w >> s >> c;
        pq.push(Key(w, s, true));
        pq.push(Key(w, s+c, false));
    }

    while(!pq.empty()){
        Key k = pq.top();
        pq.pop();
        if(!k.borrow){
            i = 1;
            while(a[i] != -1)
                i++;
            a[i] = k.num;
        }else{
            i = 1;
            while(a[i] != k.num)
                i++;
            a[i] = -1;
        }
    }

    for(i = 1; i < n+1; i++)
        cout << a[i] << " ";

    return 0;
}