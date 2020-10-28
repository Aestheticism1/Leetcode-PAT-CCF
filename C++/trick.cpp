// #include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
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

// 加速C++ IO
void accelerate_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // IO
}

// map转vector排序
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}
void map_sort(){
    unordered_map<int, int> m;
    m[6] = 3, m[5] = 8, m[4] = 9;
    vector<pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    for(auto x: v){
        cout << x.first << " " << x.second << endl;
    }
}

int main()
{
    // setprecision();
    // transfer();
    // accelerate_io();
    map_sort();
    return 0;
}