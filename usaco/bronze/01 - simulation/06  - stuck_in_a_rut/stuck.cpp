#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <map>
using namespace std;
#define ll 		long long
#define ull 	unsigned long long
#define ld 		long double
#define MOD  	pow(10,9)+7;
#define INF_INT	(1<<30)
#define INF_LL 	(1L<<62)
#define ORIENTATION 0
#define POS_X 1
#define POS_Y 2
#define IS_LOCKED 3
#define GRASS_EATEN 4 

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
	ll n,x,y;
	ll lx=pow(10,9),ly=pow(10,9),hx=-1,hy=-1;
	string o;
	vector<array<ll,5>> map;
	std::set<pair<ll,ll>> rutted_blocks;
	cin>>n;
	for (size_t i = 0; i < n; i++)
	{
		cin>>o>>x>>y;
		//N,E | x | y | locked or not locked | GRASS EATEN
		map.push_back({o[0],x,y,false,1});
		if(x<lx)lx=x;
		if(x>hx)hx=x;
		if(y<ly)ly=y;
		if(y>hy)hy=y;
	}
	// for (size_t i = 0; i < n; i++)
	// {
	// 	cout<<(char)map[i][0]<<"\t"<<map[i][1]<<"\t"<<map[i][2]<<"\n";
	// }
	ll hours=0;
	ll locked_cows=0;
	bool terminate=false;
	while(hours<200000){
		if(locked_cows==n){
			break;
		}
		locked_cows=0;
		hours+=1;
		// cout<<"Hours :"<<hours<<" Terminate "<<terminate<<"\n";
		//detect-collisions
		for (size_t i = 0; i < n; i++)
		{
			if(map[i][IS_LOCKED]){
				locked_cows+=1;
				continue;
			}
			// cout<<"Cow "<<i<<" status is ";
			if(
				(rutted_blocks.find({map[i][POS_X]+1,map[i][POS_Y]})!=rutted_blocks.end() && 
				map[i][ORIENTATION]=='E') || 
				(rutted_blocks.find({map[i][POS_X],map[i][POS_Y]+1})!=rutted_blocks.end() && 
				map[i][ORIENTATION]=='N')){
					map[i][IS_LOCKED]=true;
					// cout<<"IS LOCKED cause "<<map[i][POS_X]<<"-"<<map[i][POS_Y]<<" exists\n";
			}
			else{
				map[i][GRASS_EATEN]+=1;
				// cout<<"EAT GRASS cause "<<map[i][POS_X]<<"-"<<map[i][POS_Y]<<" does not exist\n";
			}
			
		}
		//for to update positions
		for (size_t i = 0; i < n ; i++)
		{
			if(map[i][IS_LOCKED])continue;

			if(map[i][ORIENTATION]=='E'){ //goes east
				map[i][POS_X]+=1;
			}
			else{ //goes north
				map[i][POS_Y]+=1;
			}
			rutted_blocks.insert({map[i][POS_X],map[i][POS_Y]});
		}
		//to detect infinities
		for (size_t i = 0; i < n ; i++)
		{
			if(map[i][IS_LOCKED])continue;
			// bool out_of_initial_box = lx>map[i][POS_X] || hx<map[i][POS_X] || ly>map[i][POS_Y] || hy<map[i][POS_Y];
			// bool out_of_initial_box2 = (hx<map[i][POS_X] && map[i][ORIENTATION]=='E') || (hy<map[i][POS_Y] && map[i][ORIENTATION]=='N');
			bool out_of_initial_box3 = hx<map[i][POS_X] || hy<map[i][POS_Y];

			
			if(out_of_initial_box3){
				map[i][IS_LOCKED]=true;
				map[i][GRASS_EATEN]=-1;
			}
		}

		//for debug
		// for (size_t i = 0; i < n; i++)
		// {	
		// 	cout<<"\t\t Cow "<<i<<" To position "<<map[i][POS_X]<<"-"<<map[i][POS_Y]<<"\n";
		// }
	}
	for (size_t i = 0; i < n; i++)
	{	
		if(map[i][GRASS_EATEN]==-1){
			cout<<"Infinity\n";
		}
		else{
			cout<<map[i][GRASS_EATEN]<<"\n";
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	solve();
	return 0;
}