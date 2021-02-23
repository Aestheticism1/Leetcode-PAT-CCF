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

template<class S, class T>
std::string join_str(std::vector<T>& elems, S& delim) {
    std::stringstream ss;

    typename std::vector<T>::iterator e = elems.begin();

    ss << *e++;

    for (; e != elems.end(); ++e) {
        ss << delim << *e;

    }

    return ss.str();

}

std::vector<std::string> split_str(const std::string& s, char delimiter){
    std::vector<std::string> tokens;

    std::string token;

    std::istringstream tokenStream(s);

    while ( std::getline(tokenStream, token, delimiter) )

        tokens.push_back(token);

    return tokens;

}
 
int main()
{
	// vector<string>ret = testSplit("how many credits?", " ");
	// for(int i = 0 ; i < ret.size(); ++i)
	// {
	// 	cout<<ret[i]<<endl;
	// }

	vector< string >vv = { "a", "b", "c" };
    std::string outStr = join_str( vv, "|" );
	cout << outStr << endl;
    vector< string > vv2 = split_str(  outStr,  '|' );
	
	return 0;
}