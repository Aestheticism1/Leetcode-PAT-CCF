#include <iostream>
#include <vector>
using namespace std;

struct Person{
    string name;
    int age, worth;
    Person(string n, int a, int w): name(n), age(a), worth(w){}
};

int main()
{
    int N, K;
    cin >> N >> K;
    vector<Person> forbes;
    while(N--){
        string name;
        int age, worth;
        cin >> name >> age >> worth;
        forbes.push_back(Person(name, age, worth));
    }
    sort(forbes.begin(), forbes.end(), [](Person& p1, Person& p2){
        if(p1.worth != p2.worth)
            return p1.worth>p2.worth;
        else if(p1.age != p2.age)
            return p1.age < p2.age;
        else
            return p1.name < p2.name;
    });
    for(int k = 1; k <= K; ++k){
        int num, min, max;
        cin >> num >> min >> max;
        
        printf("Case #%d:\n", k);
        int cnt = 0;
        for(int j = 0; j < forbes.size(); ++j){
            if(forbes[j].age >= min && forbes[j].age <= max && cnt < num){
                cnt++;
                printf("%s %d %d\n", forbes[j].name.c_str(), forbes[j].age, forbes[j].worth);
                if(cnt == num)
                    break;
            }
        }
        if(cnt == 0)
            printf("None\n");
    }
    return 0;
}