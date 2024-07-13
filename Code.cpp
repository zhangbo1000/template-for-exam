//Please remember it instead of copy.

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<complex>
#include<vector>
#include<stack>
#include<random>
#include<queue>
#include<map>
#include<unordered_map>
#include<set>
using namespace std;

namespace code{
	template<typename _Tp>
	_Tp max(const _Tp& x,const _Tp& y){
		return x<y?y:x;
	}
	template<typename _Tp,typename..._Rest>
	_Tp max(const _Tp& x,const _Rest&... rest){
		return max(x,max(rest...));
	}
	template<typename _Tp>
	_Tp min(const _Tp& x,const _Tp& y){
		return x<y?x:y;
	}
	template<typename _Tp,typename..._Rest>
	_Tp min(const _Tp& x,const _Rest&... rest){
		return min(x,min(rest...));
	}
	char gtc(){
		static char tmp[100000],*p1(0),*p2(0);
		if(p1==p2)p2=(p1=tmp)+fread(tmp,1,100000,stdin);
		return *p1++;
	}
	void read(int& x){
		char c;
		while((c=gtc())<'0');
		x=c^'0';
		while((c=gtc())>='0')x=(x<<1)+(x<<3)+(c^'0');
	}
	using ll=long long;
	using uint=unsigned int;
	using size_t=unsigned int;
	using ull=unsigned long long;
#define F(i,x,y) for(size_t i=(x);i<=(y);i++)
#define R(i,x,y) for(size_t i=(x);i>=(y);i--)
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
	constexpr double pi=acos(-1);
//#define sort stable_sort
//	constexpr size_t N=100005;
	signed main(){
#ifdef DEBUG
		freopen("1.txt","r",stdin);
#endif
//		cin.tie(0)->sync_with_stdio(0);
		return 0;
	}
}

signed main(){return code::main();}
