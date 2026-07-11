#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <map>
#include <algorithm>

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
	 * delete rutted blocks to reduce memory usage
	 */
	ll n,x,y;
	ll lx=pow(10,9),ly=pow(10,9),hx=-1,hy=-1;
	ll min_current_x=INF_LL,min_current_y=INF_LL;
	ll can_delete_min_x=false,can_delete_min_y=false;
	string o;
	vector<array<ll,6>> map;
	// std::set<pair<ll,ll>> rutted_blocks;
	std::map<ll,set<ll>> rutted_blocks;
	cin>>n;
	for (size_t i = 0; i < n; i++)
	{
		cin>>o>>x>>y;
		//N,E | x | y | locked or not locked | GRASS EATEN | ORDER
		map.push_back({o[0],x,y,false,1,(ll)i});
		if(x<lx)lx=x;
		if(x>hx)hx=x;
		if(y<ly)ly=y;
		if(y>hy)hy=y;
	}
	// std::sort(map.begin(),map.end(),byCoord);
	// cout<<"--------------\n";
	// for (size_t i = 0; i < n; i++)
	// {
	// 	cout<<map[i][POS_X]<<"-"<<map[i][POS_Y]<<"\n";
	// }
	// cout<<"--------------\n";
	
	int hours=0;
	int cows_locked=0;
	while(hours<100000){
		hours+=1;
		cows_locked=0;

		//find smallest y
		can_delete_min_y=true;
		for (size_t i = 0; i < n; i++)
		{
			if(map[i][POS_Y]==min_current_y)can_delete_min_y=false;
		}


		//detect collisions
		for (size_t i = 0; i < n; i++)
		{
			if(map[i][IS_LOCKED]) {
				cows_locked+=1;
				continue;
			}
			auto x_p1_iter = rutted_blocks.find(map[i][POS_X]+1);
			ll xp1=x_p1_iter==rutted_blocks.end()?-1:map[i][POS_X]+1;
			ll y = (x_p1_iter==rutted_blocks.end()||(x_p1_iter->second.find(map[i][POS_Y])==x_p1_iter->second.end()))?-1:map[i][POS_Y];

			auto x_iter = rutted_blocks.find(map[i][POS_X]);
			ll x=x_iter==rutted_blocks.end()?-1:map[i][POS_X];
			ll yp1 = (x_iter==rutted_blocks.end()||(x_iter->second.find(map[i][POS_Y]+1)==x_iter->second.end()))?-1:map[i][POS_Y]+1;

			//delete smallest y opportunistically
			if(can_delete_min_y)x_p1_iter->second.erase(min_current_y);
			if(can_delete_min_y)x_iter->second.erase(min_current_y);
			

			if(cows_locked==n) break;
			if(map[i][ORIENTATION]=='E' && xp1!=-1 && y!=-1)
				map[i][IS_LOCKED]=1;
			
			else if(map[i][ORIENTATION]=='N' && yp1!=-1&&x!=-1)
				map[i][IS_LOCKED]=1;
			else 
				map[i][GRASS_EATEN]+=1;
		}
		//rutten blocks + update positions
		if(cows_locked==n) break;
		for (size_t i = 0; i < n; i++)
		{
			if(map[i][IS_LOCKED]) continue;
			if(map[i][ORIENTATION]=='E') map[i][POS_X]+=1;
			else if(map[i][ORIENTATION]=='N') map[i][POS_Y]+=1;
			if(rutted_blocks.find(map[i][POS_X])==rutted_blocks.end()){
				rutted_blocks.insert({map[i][POS_X],{map[i][POS_Y]}});
			}
			else{
				//delete smallest y opportunistically
				auto & sec = (rutted_blocks.find(map[i][POS_X])->second);
				sec.insert(map[i][POS_Y]);
				
				if(can_delete_min_y)sec.erase(min_current_y);
			}
		}
		//infinities
		//reduces ram size by 60+%
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
		//delete unused rutted blocks by X
		can_delete_min_x=true;
		for (size_t i = 0; i < n; i++)
		{
			if(map[i][POS_X]==min_current_x)can_delete_min_x=false;
		}
		if(can_delete_min_x)rutted_blocks.erase(min_current_x);
		
		
	}
	//results
	// std::sort(map.begin(),map.end(),original);
	for (size_t i = 0; i < n; i++)
	{	
		if(map[i][GRASS_EATEN]==-1||!map[i][IS_LOCKED]){
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