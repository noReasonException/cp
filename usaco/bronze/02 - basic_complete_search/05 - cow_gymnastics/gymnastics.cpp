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
	ll k,n,tmp,pairs=0,pos_i=0,pos_j=0;
	cin>>k>>n;
	bool consistent=false;
	vector<vector<int>> runs;
	for (size_t run = 0; run < k; run++)
	{
		for (size_t cow = 0; cow < n; cow++)
		{
			cin>>tmp;
			if(cow==0)runs.push_back(std::vector<int>());
			runs[run].push_back(tmp);
		}	
	}


	for (size_t i = 0; i < n; i++) //for every i cow
	{
		for (size_t j = 0; j < n; j++) //for every j cow
		{
			if(i==j)continue;
			consistent=true;//let be consistent
			for (size_t run = 0; run < k; run++) //for every run
			{
				//for cow i and cow j on run k
				//find position i on run k
				//find position j on  run k
				//is it?
				for (size_t l = 0; l < n; l++)//find the position of i and j on kth run
				{
					if(i+1==runs[run][l])pos_i=l;
					if(j+1==runs[run][l])pos_j=l;
				}
				if(pos_i>pos_j){
					consistent=false;//if at least 1 pair has different ordering, then its not a consistent pair
					break;
				}
			}
			if(consistent) {
				pairs+=1;
				// cout<<i+1<<"\t"<<j+1<<"\t is consistent to every run\n";
			}
			
		}
		
	}
	cout<<pairs<<"\n";
	
	
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);
	solve();
	return 0;
}