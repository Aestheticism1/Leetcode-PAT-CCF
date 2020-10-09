#include <iostream> 
#include <ctime>  
using namespace std;

typedef unsigned long long ull;
clock_t start, ended;
 
ull q_mul(ull a, ull b, ull mod ) //快速计算 (a*b) % mod
{
    a %= mod;
    b %= mod;
	ull ans = 0;	// 初始化
	while(b)				//根据b的每一位看加不加当前a
	{
		if(b & 1){			//如果当前位为1
			ans += a;       //ans+=a
            if(ans >= mod)
                ans -= mod;
        }  
		b >>= 1;			//b向前移位
		a <<= 1;		    //更新a
        if(a >= mod)
            a -= mod;
	}
	return ans;
}
 
ull q_pow(ull a, ull b, ull mod) //快速计算 (a^b) % mod
{
	ull ans = 1; // 初始化
	while(b)//根据b的每一位看乘不乘当前a
	{
        //如果当前位为1
		if(b & 1)
			ans = q_mul(ans, a, mod); //ans*=a
		b >>= 1;						//b向前移位
		a = q_mul(a, a, mod);			//更新a
	}
	return ans;
}

int main( )
{
	long long a, b, n;
    double endtime;
	while(cin >> a >> b >> n)
	{
        start = clock();
		cout << "a*b%n = " << q_mul(a, b, n) << endl;
        ended = clock();
        endtime=(double)(ended-start)/CLOCKS_PER_SEC;
        cout << "快速乘：" << endtime * 1000 << "ms" << endl;
        
        start = clock();
		cout << "a^b%n = " << q_pow(a, b, n) << endl;
        ended = clock();
        endtime=(double)(ended-start)/CLOCKS_PER_SEC;
        cout << "快速幂：" << endtime * 1000 << "ms" << endl;
	}
	return 0;
}