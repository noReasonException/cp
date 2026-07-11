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
	ll len_x,len_y;
	string o;
	vector<array<ll,5>> map;
	std::set<pair<ll,ll>> rutted_blocks;
	cin>>n;
	for (size_t i = 0; i < n; i++)
	{
		cin>>o>>x>>y;
		//N,E | x | y | locked or not locked | GRASS EATEN
		map.push_back({o[0],x,y,false,1});
	}
	/**
	 *                                                    
                                               ▲   
             .           ──▲────       ────────┼─► 
             .             │                   │   
             │             │                   │   
             │             │                   │   
   ─────────►│             │                   │   
   Long E - Short N   Short E - Long N    Equal    
	 */

	
	
	for (size_t a = 0; a < n; a++)
	{
		for (size_t b = 0; b < n; b++)
		{
			if(a==b)continue;
			if(map[a][ORIENTATION]==map[b][ORIENTATION]) continue;
			len_x=(map[b][POS_X]-map[a][POS_X]);
			len_y=(map[a][POS_Y]-map[b][POS_Y]);
			cout<<(char)(map[a][ORIENTATION])<<"\t"<<len_x<<"\t"<<len_y<<"\n";
			//SELN
			if(map[a][ORIENTATION]=='N'&&len_x>0&&len_y>0&&len_x<len_y){
				map[a][IS_LOCKED]=true;
				map[a][GRASS_EATEN]=len_y;
				// cout<<"yes 1\n";
			}
			//LESN
			else if(map[a][ORIENTATION]=='E'&&len_x>0&&len_y>0&& len_x>len_y){
				map[a][IS_LOCKED]=true;
				map[a][GRASS_EATEN]=len_x;
				// cout<<"yes 1\n";
			}
			else{
				// cout<<"no\n";
			}
		}
	}

	cout<<"\n";
	//results
	for (size_t i = 0; i < n; i++)
	{	
		if(!map[i][IS_LOCKED]){
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