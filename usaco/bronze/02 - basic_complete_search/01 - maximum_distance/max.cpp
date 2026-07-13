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
	ll n,tmp;
	cin>>n;
	vector<ll> x,y;
	for (size_t i = 0; i < n; i++)
	{
		cin>>tmp;
		x.push_back(tmp);
	}
	for (size_t i = 0; i < n; i++)
	{
		cin>>tmp;
		y.push_back(tmp);
	}

	// for (size_t i = 0; i < n; i++)
	// {
	// 	cout<<x[i]<<"\t"<<y[i]<<"\n";
	// }
	ll max=-1;
	ll dist = 0;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{

			if(i==j)continue;
			dist=pow(abs(x[i]-x[j]),2)+pow(abs(y[i]-y[j]),2);
			if(dist>max)max=dist;
		}
		
	}
	cout<<max<<"\n";
	
	
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	solve();
	return 0;
}