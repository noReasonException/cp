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
#define ORDER 5

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

// Custom comparison function
bool byCoord(array<ll,6> mapa, array<ll,6> mapb)
{
    // Custom comparison logic
    return mapa[POS_X]==mapb[POS_X]?(mapa[POS_Y]<mapb[POS_Y]):(mapa[POS_X]<mapb[POS_X]);
}
bool original(array<ll,6> mapa, array<ll,6> mapb)
{
    // Custom comparison logic
    return mapa[ORDER]<mapb[ORDER];
}
void solve(){
	/**
	 *  completely different approach
	 * 	
	 */
	ll n,x,y;
	ll lx=pow(10,9),ly=pow(10,9),hx=-1,hy=-1;
	ll chx=-1,chy=-1;
	string o;
	vector<array<ll,6>> map;
	std::set<pair<ll,ll>> rutted_blocks;
	cin>>n;
	for (size_t i = 0; i < n; i++)
	{
		cin>>o>>x>>y;
		//N,E | x | y | locked or not locked | GRASS EATEN
		map.push_back({o[0],x,y,false,1,(ll)i});
		if(x<lx)lx=x;
		if(x>hx)hx=x;
		if(y<ly)ly=y;
		if(y>hy)hy=y;
	}

	std::sort(map.begin(),map.end(),byCoord);
	int hours=0;
	int init=0;
	// for (size_t i = 0; i < n; i++)
	// {
	// 	cout<<map[i][POS_X]<<"-"<<map[i][POS_Y]<<"\n";
	// }
	
		for (size_t i = init; i < n; i++)
		{
			/**
			 * B=====
			 * A====
			 */
			if(map[i][ORIENTATION]=='E' && i+1<n && map[i+1][ORIENTATION]=='E' && map[i][POS_X]<map[i+1][POS_X]){
				map[i][IS_LOCKED]=true;
				map[i][GRASS_EATEN]=-1;
				init+=1;
			}
			/**
			 * A========    B=========
			 */
			else if(map[i][ORIENTATION]=='E' && i+1<n && map[i+1][ORIENTATION]=='E' && map[i][POS_X]==map[i+1][POS_X]){
				map[i][IS_LOCKED]=true;
				map[i][GRASS_EATEN]=abs(map[i+1][POS_Y]-map[i][POS_Y]);
				init+=1;
			}
			/**
			 *					|
			 * 					|
			 *  				B
			 * A=========== 
			 */
			else if(map[i][ORIENTATION]=='E' && i+1<n && map[i+1][ORIENTATION]=='N' && map[i][POS_X]<map[i+1][POS_X]){
				map[i][IS_LOCKED]=true;
				map[i][GRASS_EATEN]=-1;
				init+=1;
			}
			/**
			 *					|
			 * 					|
			 *  				|
			 * A=========== 	B
			 */
			else if(map[i][ORIENTATION]=='E' && i+1<n && map[i+1][ORIENTATION]=='N' && map[i][POS_X]==map[i+1][POS_X]){
				map[i][IS_LOCKED]=true;
				map[i][GRASS_EATEN]=abs(map[i+1][POS_Y]-map[i][POS_Y]);
				init+=1;
			}
			/**
			 *  |  	|
			 * 	|	|
			 * 	|	|
			 * 	A	B
			 */
			else if(map[i][ORIENTATION]=='N' && i+1<n && map[i+1][ORIENTATION]=='N' && map[i][POS_Y]<map[i+1][POS_Y]){
				map[i][IS_LOCKED]=true;
				map[i][GRASS_EATEN]=-1;
				init+=1;
			}
			/**	|
			 *  B  	
			 * 		
			 * 	|	
			 * 	A	
			 */
			else if(map[i][ORIENTATION]=='N' && i+1<n && map[i+1][ORIENTATION]=='N' && map[i][POS_X]<map[i+1][POS_X]){
				map[i][IS_LOCKED]=true;
				map[i][GRASS_EATEN]=abs(map[i][POS_Y]-map[i+1][POS_Y]);
				init+=1;
			}
			/**
			 * 		B-----
			 * 	
			 * 	|
			 * 	A
			 * 
			 */
			else if(map[i][ORIENTATION]=='N' && i+1<n && map[i+1][ORIENTATION]=='E' && map[i][POS_Y]<map[i+1][POS_Y]){
				map[i][IS_LOCKED]=true;
				map[i][GRASS_EATEN]=-1;
				init+=1;
			}
			/**
			 *  B-----
			 * 	
			 * 	|
			 * 	A
			 * 
			 */
			else if(map[i][ORIENTATION]=='N' && i+1<n && map[i+1][ORIENTATION]=='E' && map[i][POS_Y]==map[i+1][POS_Y]){
				map[i][IS_LOCKED]=true;
				map[i][GRASS_EATEN]=abs(map[i+1][POS_Y]-map[i][POS_Y]);
				init+=1;
			}
		}
	
	for (size_t i = init; i < n; i++)
	{
		map[i][IS_LOCKED]=true;
		map[i][GRASS_EATEN]=-1;
	}
	



	
	std::sort(map.begin(),map.end(),original);
	//results
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