#include <iostream>
#include <vector>
#include <set>
#include <math.h>
using namespace std;
#define ll 		long long
#define ull 	unsigned long long
#define ld 		long double
#define MOD  	pow(10,9)+7;
#define INF_INT	(1<<30)
#define INF_LL 	(1L<<62)

/**
	? Stuff to look for ->
    * stay organised
    * int overflows, array bounds, etc.
    * special cases (n=1)?
    * do something instead of nothing
    * timebox your approach
    * simple is better than complex
    * n % mod = (n % mod + mod) % mod;
    * long long instead of int
*/
ll exp_trivial(ll n,ll a){
	ll ans = n;
    for (ll i = 0; i < a-1; i++)
    {
        ans*=n;
    }
    return ans;
}
ll exp_fast(ll base,ll exp){
    if(exp==0) return 1;
    if(exp==1) return base;
	ll result = 1;
    ll a=exp;
    ll newBase = base;
    while(a!=0){
        if(a&1)result*=newBase;
        newBase*=newBase;
        a=a>>1;
    }
    return result;
}
ll exp_fast_thick(ll base,ll exp){
    if(exp==0) return 1;
    if(exp==1) return base;
	ll result = 1;
    ll a=exp;
    ll newBase = base;
    while(a!=0){
        result*=(a&1)?newBase:1;
        newBase*=newBase;
        a=a>>1;
    }
    return result;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

    ll answer = exp_fast_thick(3,13);
    std::cout<<"->>>>>"<<answer<<"\n";
	return 0;
}