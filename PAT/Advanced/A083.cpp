#include<iostream>
using namespace std;
struct Student{
    string name,id;
    int grade;
};
int main(){
    int N,g1,g2;
    scanf("%d",&N);
    Student stu[N];
    for(int i=0;i<N;++i)
        cin>>stu[i].name>>stu[i].id>>stu[i].grade;
    sort(stu,stu+N,[](const Student&s1,const Student&s2){
        return s1.grade>s2.grade;
    });
    scanf("%d%d",&g1,&g2);
    bool output=false;
    for(int i=0;i<N;++i)
        if(stu[i].grade>=g1&&stu[i].grade<=g2){
            printf("%s %s\n",stu[i].name.c_str(),stu[i].id.c_str());
            output=true;
        }
    if(!output)
        printf("NONE");
    return 0;
}