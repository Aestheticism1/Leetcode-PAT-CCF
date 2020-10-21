#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <regex>
#include <unordered_map>

using namespace std;

stringstream all;   //按空格字符分割字符串
unordered_map<string, string> ans;

//深搜
bool DFS(string key){
    string value;
    all >> value;
    // cout << value << endl;
    if(value == "}"){       //当前值对象已读取完毕
        return false;
    }else if(value == "{"){
        if(key != "")
            ans[key] = "{}";
        while(DFS(key));    //递归处理值对象
    }else{                  //键或值
        string word = value.substr(1, value.rfind('"')-1);
        if(value.back() == ':'){    //键
            DFS((key == "") ? word : key+'.'+word);    //递归处理其值
        }else{              //值
            ans[key] = word;
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    string s = "";
    string tmp;
    ifstream in(".//ccf//data.txt");    //从文件读取输入
    for(int i = 0; i < n; i++){
        getline(in, tmp);
        s += tmp;
    }
    in.close();
    s=regex_replace(s, regex(" "), "");    //去掉s中所有的空格字符
    s=regex_replace(s, regex("\\\\\""), "\"");    //将两个连续的\"字符转换为单个"字符
    s=regex_replace(s, regex("\\\\\\\\"), "\\");  //将两个连续的\\字符转换为单个\字符
    s=regex_replace(s, regex(","), ", ");     //在每个,字符后添加一个空格字符
    s=regex_replace(s, regex(":"), ": ");     //在每个:字符后添加一个空格字符
    s=regex_replace(s, regex("\\{"), " { ");  //在每个{字符左右均添加空格字符
    s=regex_replace(s, regex("\\},?"), " } ");    //在每个}字符左右均添加空格字符

    all << s;
    DFS("");

    string q;
    while(m--){
        cin >> q;
        if(ans.find(q) != ans.end()){
            if(ans[q] == "{}")
                cout << "OBJECT" << endl;
            else
                cout << "STRING " << ans[q] << endl;
        }else{
            cout << "NOTEXIST" << endl;
        }
    }

    return 0;
}   