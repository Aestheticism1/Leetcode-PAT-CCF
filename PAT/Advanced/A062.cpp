#include <iostream>

using namespace std;

struct Person{
    int id, virtue, talent, total, level;
};

int main()
{
    int N, L, H;
    cin >> N >> L >> H;
    Person people[N];
    int index = 0;
    for(int i = 0; i < N; ++i){
        int id, v, t;
        cin >> id >> v >> t;
        if(v >= L && t >= L){
            people[index].id = id;
            people[index].virtue = v;
            people[index].talent = t;
            people[index].total = v + t;
            if(v >= H && t >= H)
                people[index].level = 1;
            else if(v >= H && t < H)
                people[index].level = 2;
            else if(v < H && t < H && v >= t)
                people[index].level = 3;
            else
                people[index].level = 4;
            index++;            
        }
    }
    printf("%d", index);
    if(index > 0)
        printf("\n");
    sort(people, people + index, [](Person& p1, Person& p2){
        if(p1.level != p2.level){
            return p1.level < p2.level;
        }else if(p1.total != p2.total){
            return p1.total > p2.total;
        }else if(p1.virtue != p2.virtue){
            return p1.virtue > p2.virtue;
        }else
            return p1.id < p2.id;
    });
    for(int i = 0; i < index; ++i){
        if(i != index - 1){
            printf("%08d %d %d\n", people[i].id, people[i].virtue, people[i].talent);
        }else{
            printf("%08d %d %d", people[i].id, people[i].virtue, people[i].talent);
        }
    }
    return 0;
}