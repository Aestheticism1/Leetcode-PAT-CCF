#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

float PRICE[25];
struct Time{
    int M,d,h,m,time,online=0;
    bool operator < (const Time& t) const {
        return this->time < t.time;
    }
};
map<string, set<Time> > records;

float getBill(Time t, int d){
    float bill = 0;
    for(int i=0; i < t.h; ++i){
        bill += PRICE[i] * 60;
    }
    bill += t.m * PRICE[t.h] + (t.d - d) * PRICE[24] * 60;
    return bill / 100;
}

int main()
{
    for(int i = 0; i < 24; ++i){
        cin >> PRICE[i];
        PRICE[24] += PRICE[i];
    }
    int num;
    cin >> num;
    while(num--){
        string name;
        cin >> name;
        Time t;
        scanf("%d:%d:%d:%d", &t.M, &t.d, &t.h, &t.m);
        t.time = (t.d * 24 + t.h) * 60 + t.m;
        string online;
        cin >> online;
        if(online == "on-line")
            t.online = 1;
        records[name].insert(t);
    }

    for(auto it = records.begin(); it != records.end(); ++it){
        bool output = false;
        float sum = 0;
        for(auto t = (it->second).begin(); t != (it->second).end(); ++t){
            auto tnext = t;
            ++tnext;
            for(; tnext != (it->second).end() && !(t->online && !tnext->online); ++t, ++tnext);

            if(tnext != (it->second).end()){
                if(!output){
                    printf("%s %02d\n", (it->first).c_str(), t->M);
                    output = true;
                }
                printf("%02d:%02d:%02d %02d:%02d:%02d ", t->d, t->h, t->m, tnext->d, tnext->h, tnext->m);
                printf("%d ", tnext->time - t->time);
                float bill = getBill(*tnext, t->d) - getBill(*t, t->d);
                printf("$%.2f\n", bill);
                sum += bill;
            }
        }
        if(output)
            printf("Total amount: $%.2f\n", sum);
    }
    return 0;
}