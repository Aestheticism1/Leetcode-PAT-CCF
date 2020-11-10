#include <iostream>
#include <vector>

using namespace std;

struct Stu{
    string name, id;
    char gender;
    int grade;
    Stu(string n, string i, char g, int gr): name(n), id(i), gender(g), grade(gr){}
};

vector<Stu> male;
vector<Stu> female;

int main()
{
    int N;
    cin >> N;
    while(N--){
        string name, id;
        char gender;
        int grade;
        cin >> name >> gender >> id >> grade;
        if(gender == 'F')
            female.push_back(Stu(name, id, gender, grade));
        else
            male.push_back(Stu(name, id, gender, grade));
    }

    auto min_male = min_element(male.begin(), male.end(), [](Stu& a, Stu& b){
        return a.grade < b.grade;
    });
    auto max_female = max_element(female.begin(), female.end(), [](Stu& a, Stu& b){
        return a.grade < b.grade;
    });
    if(female.size() == 0)
        cout << "Absent" << endl;
    else
        cout << (*max_female).name << " " << (*max_female).id << endl;
    if(male.size() == 0)
        cout << "Absent" << endl;
    else 
        cout << (*min_male).name << " " << (*min_male).id << endl;
    if(female.size() == 0 || male.size() == 0)
        cout << "NA";
    else
        cout << (*max_female).grade - (*min_male).grade;
    return 0;
}