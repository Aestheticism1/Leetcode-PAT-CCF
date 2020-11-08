#include <iostream>
#include <vector>

using namespace std;

struct Record{
    string id, name;
    int point;
    Record(string i, string n, int p): id(i), name(n), point(p){}
};

vector<Record> records;

bool cmp1(Record& a, Record& b){
    return a.id < b.id;
}

bool cmp2(Record& a, Record& b){
    if(a.name == b.name)
        return a.id < b.id;
    else
        return a.name < b.name;
}

bool cmp3(Record& a, Record& b){
    if(a.point == b.point)
        return a.id < b.id;
    else
        return a.point < b.point;
}

int main()
{
    int N, C;
    cin >> N >> C;
    while(N--){
        string id, name;
        int point;
        cin >> id >> name >> point;
        records.push_back(Record(id, name, point));
    }
    switch(C){
        case 1:
            sort(records.begin(), records.end(), cmp1);
            break;
        case 2:
            sort(records.begin(), records.end(), cmp2);
            break;
        case 3:
            sort(records.begin(), records.end(), cmp3);
            break;
    }
    for(auto x: records)
        cout << x.id << " " << x.name << " " << x.point << endl;
    return 0;
}