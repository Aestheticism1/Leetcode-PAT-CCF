#include<iostream>
using namespace std;
int f(const string&s,string&temp,int N){//将字符串s的N位有效数字存储在字符串temp中，并返回指数
    int point=s.size(),index=-1;//point指示字符串s中小数点的位置，初始化为字符串s最后一位，index指示s中第一位非零数字的位置，初始化为-1
    for(int i=0;i<s.size();++i)//遍历字符串s
        if(s[i]=='.')//找出小数点位置
            point=i;
        else if(index!=-1&&temp.size()<N)//将s中最多N位有效数字存储在temp中
            temp+=s[i];
        else if(index==-1&&s[i]!='0'){//找到字符串s第一位非零数字的位置
            index=i;
            temp+=s[i];
        }
    while(temp.size()<N)//temp长度小于N，即有效数字位数小于N
        temp+="0";//在字符串末尾加足够的0保证有N位有效数字
    if(index==-1)//没有找到非零数字，说明字符串s表示的数是0
        return 0;//指数为0，返回
    point-=index;//小数点位置减去第一位非零数字位置得到指数
    return point<0?point+1:point;//当前point为负数，返回point+1；否则返回point
}
int main(){
    int N;
    string A,B,Atemp="",Btemp="";
    cin>>N>>A>>B;//读取数据
    int Aexp=f(A,Atemp,N),Bexp=f(B,Btemp,N);//得到有效数字和指数
    if(Aexp==Bexp&&Atemp==Btemp)//有效数字和指数均相等
        cout<<"YES 0."<<Atemp<<"*10^"<<Aexp;//两数相等，输出YES和科学计算法表示的字符串
    else//否则输出NO和科学计算法表示的字符串
        cout<<"NO 0."<<Atemp<<"*10^"<<Aexp<<" 0."<<Btemp<<"*10^"<<Bexp;
    return 0;
}