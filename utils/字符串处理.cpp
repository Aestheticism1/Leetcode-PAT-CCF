#include <iostream>
#include <string>
#include <vector>
#include <regex>
 
using namespace std;
 
//没有使用C++11特性
vector<string> testSplit(string srcStr, const string& delim)
{
	int nPos = 0;
	vector<string> vec;
	nPos = srcStr.find(delim.c_str());
	while(-1 != nPos)
	{
		string temp = srcStr.substr(0, nPos);
		vec.push_back(temp);
		srcStr = srcStr.substr(nPos+1);
		nPos = srcStr.find(delim.c_str());
	}
	vec.push_back(srcStr);
	return vec;
}
 
//使用C++11特性
vector<string> testSplit11(const string& in, const string& delim)
{
    vector<string> ret;
    try
    {
        regex re{delim};
        return vector<string>{
                sregex_token_iterator(in.begin(), in.end(), re, -1),
                sregex_token_iterator()
           };      
    }
    catch(const std::exception& e)
    {
        cout<<"error:"<<e.what()<<std::endl;
    }
    return ret;
}
 
int main()
{
	vector<string>ret = testSplit("how many credits?", " ");
	for(int i = 0 ; i < ret.size(); ++i)
	{
		cout<<ret[i]<<endl;
	}
	
	return 0;
}