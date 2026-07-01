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
	int game1[3] = {1,0,0};
	int game2[3] = {0,1,0};
	int game3[3] = {0,0,1};
	int *games[3] = {game1,game2,game3};
	int scores[3] = {0,0,0};
	for (size_t i = 0; i < n; i++)
	{
		cin>>a>>b;
		for (size_t i = 0; i < 3; i++)
		{
			swap = games[i][a];
			games[i][a] = games[i][b];
			games[i][b]=swap;
		}
		cin>>g;
		if(games[0][g]) scores[0]+=1;
		if(games[1][g]) scores[1]+=1;
		if(games[2][g]) scores[2]+=1;
	}	
	cout<<max(scores[0],max(scores[1],scores[2]))<<"\n";
}
void solve2(){
	int n,a,b,g;
	cin>>n;
	//without multiple arrays for each game
	//single variable declaring where the ball is per game
	int games[3]={0,1,2}; //in game i pebble is in position games[i]
	int scores[3]={0,0,0}; //score per possible game
	for (int i = 0; i < n; i++)
	{
		cin>>a>>b>>g;
		a--;b--;g--; //zero indexing
		std::swap(games[a],games[b]); //swap pebble = swap game (see proof)
		for (int i = 0; i < 3; i++) //for each possible game
		scores[games[g]]+=1;
		
		
	}
	cout<<scores[0]<<"-"<<scores[1]<<"-"<<scores[2]<<"\n";
	cout<<max(scores[0],max(scores[1],scores[2]))<<"\n";
	
	
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve2();
	return 0;
}