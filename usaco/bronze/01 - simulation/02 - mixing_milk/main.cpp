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
	int c[3] = {0,0,0};
	int m[3] = {0,0,0};
	int state=0;
	int from=0,to=1,toMilk=0,fromMilk;
	for (size_t i = 0; i < 3; i++)
	{
		cin>>c[i]>>m[i];
	}
	// cout<<"Load Complete\n";
	// for (size_t i = 0; i < 3; i++)
	// {
	// 	cout<<c[i]<<"-"<<m[i]<<"\n";
	// }
	// cout<<"Process Begin\n";
	for (size_t i = 0; i < 100; i++)
	{
		state=(state+1)%3;
		to=state;
		from=state-1>=0?state-1:2;
		//pour untill either to bucket fills up, or from bucket empties
		toMilk = m[to]+m[from]<=c[to]?m[to]+m[from]:c[to];
		fromMilk = m[to]+m[from]<c[to]?0:((m[to]+m[from])-c[to]);
		m[to]=toMilk;
		m[from]=fromMilk;
	}
	cout<<m[0]<<"\n"<<m[1]<<"\n"<<m[2]<<"\n";
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("mixmilk.in", "r", stdin);
	freopen("mixmilk.out", "w", stdout);
	solve();
	return 0;
}