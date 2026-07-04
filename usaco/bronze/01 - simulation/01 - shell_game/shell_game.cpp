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
	int n,a,b,g,swap;
	cin>>n;
	if(n==1){
		cout<<"1\n";
		return;
	}
	int game1[3] = {1,0,0};
	int game2[3] = {0,1,0};
	int game3[3] = {0,0,1};
	int *games[3] = {game1,game2,game3};
	int scores[3] = {0,0,0};
	for (size_t i = 0; i < n; i++)
	{
		cin>>a>>b;
		a--;b--;
		for (size_t i = 0; i < 3; i++)
		{
			if(games[i][a]+games[i][b]==0) continue;
			swap = games[i][a];
			games[i][a] = games[i][b];
			games[i][b]=swap;
		}
		cin>>g;
		g--;
		if(games[0][g]) scores[0]+=1;
		if(games[1][g]) scores[1]+=1;
		if(games[2][g]) scores[2]+=1;
	}	
	cout<<max(scores[0],max(scores[1],scores[2]))<<"\n";
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("shell.in", "r", stdin);
	freopen("shell.out", "w", stdout);
	solve();
	return 0;
}