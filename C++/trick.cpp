// #include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

// 按照特定格式打印小数
void setprecision(){
    float c = 2.5555566;
    cout << setiosflags(ios::fixed) << setprecision(2) << c <<endl;
}

// 字符、数字相互转换
void transfer(){
    stringstream ss;
    string a;
    double b;
    while((cin >> a) && a != "quit"){
        ss << a;
        ss >> b;
        cout << ss.str() << endl;
        cout << b << endl;
        cout << endl;
        ss.str("");
        ss.clear();
    }

    double c;
    string d;
    while((cin >> c) && c != 0){
        ss << c;
        d = ss.str();
        cout << d << endl;
        cout << endl;
        ss.str("");
    }

    /* atoi/atol */
    // string x = "3.14159";
    // double y = atoi(x.c_str());
    // cout << y << endl;
}

int main()
{
    setprecision();
    transfer();
    return 0;
}