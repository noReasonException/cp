#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
using namespace std;
#define ll 		long long
#define ull 	unsigned long long
#define ld 		long double
#define MOD  	pow(10,9)+7;
#define INF_INT	(1<<30)
#define INF_LL 	(1L<<62)

//forward refs
template <typename container> void debug(container& genericSequence,string id="None", int depth=0);

//debug utils
#ifdef DEBUG
	template <typename container> void debug(container& genericSequence,string id, int depth){
		cout<<"=============Debug ("<<id<<") START =============\n";
		string prefix = "";
		for(int i=0;i<depth;i++) prefix+="\t";

		for(auto every: genericSequence){
			cout<<prefix<<every<<"\n";
		}
		cout<<"=============Debug ("<<id<<") END =============\n";

	}
#endif
#ifndef DEBUG
	template <typename container> void debug(container& genericSequence,string id, int depth){
		return ;
	}

#endif

/**
 	*
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
void solve(){
	ll n,b,cx,cy;
	cin>>n>>b;
	vector<pair<ll,ll>> cows;
	vector<ll> cowsx,cowsy;
	for (size_t i = 0; i < n; i++)
	{
		cin>>cx>>cy;
		cows.push_back(make_pair(cx,cy));
		cowsx.push_back(cx);
		cowsy.push_back(cy);
	}
	sort(cowsx.begin(),cowsx.end());
	sort(cowsy.begin(),cowsy.end());

	if(b%2!=0)b++;
	ll cowxInd=n;
	ll cowyInd=n;

	ll m1=0,m2=0,m3=0,m4=0,m=-1,M=INF_LL;
	for (size_t i = b; i >cowsx[0] ; i-=(i-cowsx[cowxInd]+1))
	{
		cowyInd=n;
		for (size_t j = b; j >cowsy[0]; j-=(j-cowsy[cowyInd]+1))
		{
			cowyInd-=1;
			m1=0;m2=0;m3=0;m4=0;m=0;
			for (size_t l = 0; l < n; l++)
			{
				if(cows[l].first<i&&cows[l].second<j)m1+=1;	
				if(cows[l].first>i&&cows[l].second<j)m2+=1;
				if(cows[l].first<i&&cows[l].second>j)m3+=1;
				if(cows[l].first>i&&cows[l].second>j)m4+=1;
			}
			m=max(max(m1,m2),max(m3,m4));
			if(m<M)M=m;
		}
		cowxInd-=1;
	}
	// for (size_t i = 0; i < n; i++)
	// {
	// 	cout<<cowsx[i]<<"\t";
	// }
	
	
	

	cout<<M<<"\n";
	//we know that cx,cy are odd, at most b
	//a,b even
	//minimise M
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);
	solve();
	return 0;
}