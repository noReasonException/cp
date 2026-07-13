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
	ll n,k,tmp,max_diff=0;
	cin>>n>>k;
	vector<ll>diamonds;
	for (size_t i = 0; i < n; i++)
	{
		cin>>tmp;
		diamonds.push_back(tmp);
	}
	std::sort(diamonds.begin(),diamonds.end());

	// for (size_t i = 0; i < n; i++)
	// {
	// 	cout<<diamonds[i]<<"-";
	// }
	

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = i+1; j < n; j++)
		{
			if(diamonds[j]-diamonds[i]<=k && max_diff<j-i){
				max_diff=j-i;
			}
		}	
	}
	

	cout<<max_diff+1<<"\n";
	
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);
	solve();
	return 0;
}