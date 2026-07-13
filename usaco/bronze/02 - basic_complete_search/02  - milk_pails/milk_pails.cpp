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
	ll x,y,m;
	cin>>x>>y>>m;
	ll max_x=floor(m/x)+1;
	ll max_y=floor(m/y)+1;
	ll ix=0,iy=0;
	ll best=-1;
	ll bestx = 0;
	ll besty = 0;
	ll curr;

	for (size_t ix = 0; ix <= max_x; ix++)
	{
		for (size_t iy = 0; iy <= max_y; iy++)
		{
			curr=ix*x+iy*y;
			if(curr<=m&&curr>best){
				best=curr;
				bestx=ix;
				besty=iy;
			}
		}
	}
	cout<<best<<"\n";
	

	

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("pails.in", "r", stdin);
	freopen("pails.out", "w", stdout);
	solve();
	return 0;
}