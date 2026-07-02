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

struct obj{
	int len;
	int speed;
};

struct obj makePair(int len,int speed){
	return obj{len,speed};
}

void solve(){
	//a,b temp
	int n,m,x,y;
	cin>>n>>m;
	//len,max_speed
	vector<obj> road_segments;
	//len,bessies_speed
	vector<obj> bessie_segments;

	for (size_t i = 0; i < n; i++)
	{
		cin>>x>>y;
		road_segments.push_back(makePair(x,y));
	}
	for (size_t i = 0; i < m; i++)
	{
		cin>>x>>y;
		bessie_segments.push_back(makePair(x,y));
	}

	// for (size_t i = 0; i < n; i++)
	// {
	// 	cout<<road_segments[i].first<<"\t"<<road_segments[i].second<<"\n";
	// }
	// for (size_t i = 0; i < n; i++)
	// {
	// 	cout<<bessie_segments[i].first<<"\t"<<bessie_segments[i].second<<"\n";
	// }

	//a:road_index,b:bessie_index
	int max_exceed_limit=0;
	int road_index=0;
	int bessie_index=0;
	int max_speed=0,bessies_speed=0;

	while(road_index<road_segments.size()||bessie_index<bessie_segments.size())
	{
		//this is nessesary as we can overshoot the indexes, and not having access to the last speed of said segment
		if(road_index<road_segments.size()) max_speed=road_segments[road_index].speed;
		if(bessie_index<bessie_segments.size()) bessies_speed=bessie_segments[bessie_index].speed;
		//op 1: find if violated in this section the speed limit
		//op 2: compare it with max_exceed_limit, keep it if it is bigger
		if(bessies_speed>max_speed && bessies_speed-max_speed>max_exceed_limit){
			// cout<<"In\n";
			max_exceed_limit = bessies_speed-max_speed;
		}
		//op 3: update either a or b,  both or the len's (in case of excess)

		if(road_segments[road_index].len==bessie_segments[bessie_index].len){
			road_index+=1;
			bessie_index+=1;
		}
		else if(road_segments[road_index].len>bessie_segments[bessie_index].len){
			road_segments[road_index].len-=bessie_segments[bessie_index].len;
			bessie_index+=1;
		}
		else{
			bessie_segments[bessie_index].len-=road_segments[road_index].len;
			road_index+=1;
		}
	}
	// cout<<"Result is "<<max_exceed_limit<<"\n";
	cout<<max_exceed_limit<<"\n";
	
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("speeding.in", "r", stdin);
	freopen("speeding.out", "w", stdout);
	solve();
	return 0;
}