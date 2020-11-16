#include <iostream>
#include <queue>

using namespace std;

struct Mouse{
    int weight, level;
};

int main()
{
    int P, G;
    cin >> P >> G;
    Mouse mouse[P];
    for(int i = 0; i < P; ++i)
        cin >> mouse[i].weight;
    queue<int> q;
    int tmp;
    for(int i = 0; i < P; ++i){
        cin >> tmp;
        q.push(tmp);    //将初始顺序放入队列中
    }
    while(q.size() > 1){    //在队列元素个数大于1，即进行比较的老鼠多于1只时继续循环
        int extra = q.size() % G == 0 ? G : q.size() % G;   //extra存储最后一组老鼠数量
        int group = (q.size() - 1) / G;    //group存储当前比较的老鼠分的组数-1
        for(int i = 0; i < group+1; ++i){   //对这group+1组老鼠进行比较，选出晋级的老鼠
            int len = i == group ? extra : G;   //存储当前组的老鼠数量
            int max = q.front();
            for(int j = 0; j < len; ++j){
                mouse[q.front()].level = group + 2;    //将当前组的老鼠的排名置为group+2，即组数+1
                if(mouse[q.front()].weight > mouse[max].weight)
                    max = q.front();
                q.pop();
            }
            q.push(max);    //将体重最大的老鼠在数组中的索引放入队列中
        }
    }
    mouse[q.front()].level = 1;
    for(int i = 0; i < P; ++i)
        printf("%s%d",i > 0 ? " " : "", mouse[i].level);
    return 0;
}