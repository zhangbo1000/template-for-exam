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
	using ll=long long;
	using uint=unsigned int;
	using size_t=unsigned int;
	using ull=unsigned long long;
#define F(i,x,y) for(size_t i=(x);i<=(y);i++)
#define R(i,x,y) for(size_t i=(x);i>=(y);i--)
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
	constexpr double pi=acos(-1);
#define sort stable_sort
	constexpr size_t N=100005;
	struct plane{
		size_t bg,ed;
		constexpr plane():bg(0),ed(0){}
	}a[N],b[N];
	bool operator<(const plane& x,const plane& y){
		return x.bg<y.bg;
	}
	struct landed_p{
		size_t ed,ind;
		constexpr landed_p(const size_t& _1=0,const size_t& _2=0):ed(_1),ind(_2){}
	};
	bool operator<(const landed_p& x,const landed_p& y){
		return x.ed>y.ed;
	}
	size_t ansa[N],ansb[N];
	priority_queue<landed_p>land;
	priority_queue<size_t,vector<size_t>,greater<size_t>>empland;
	signed main(){
#ifdef DEBUG
		freopen("1.txt","r",stdin);
#endif
		cin.tie(0)->sync_with_stdio(0);
		size_t n,m1,m2;
		cin>>n>>m1>>m2;
		F(i,1,m1){
			cin>>a[i].bg>>a[i].ed;
		}
		F(i,1,m2){
			cin>>b[i].bg>>b[i].ed;
		}
		size_t tmp=max(m1,m2);
		F(i,1,tmp){
			empland.push(i);
		}
		sort(a+1,a+1+m1);
		sort(b+1,b+1+m2);
		F(i,1,m1){
			while(!land.empty()&&land.top().ed<a[i].bg){
				empland.push(land.top().ind);
				land.pop();
			}
			//	debug(i);
			//	if(!land.empty())debug(land.top().ed);
			//	debug(empland.top());
			//	debug(a[i].bg);
			//	debug(a[i].ed);
			ansa[empland.top()]++;
			land.push(landed_p(a[i].ed,empland.top()));
			empland.pop();
		}
		while(!land.empty()){
			empland.push(land.top().ind);
			land.pop();
		}
		F(i,1,m2){
			while(!land.empty()&&land.top().ed<b[i].bg){
				empland.push(land.top().ind);
				land.pop();
			}
			ansb[empland.top()]++;
			land.push(landed_p(b[i].ed,empland.top()));
			empland.pop();
		}
		size_t ans=0;
		F(i,2,n){
			ansa[i]+=ansa[i-1];
			ansb[i]+=ansb[i-1];
		}
		F(i,0,n){
			ans=max(ans,ansa[i]+ansb[n-i]);
		}
		cout<<ans;
		return 0;
	}
}

signed main(){return code::main();}
