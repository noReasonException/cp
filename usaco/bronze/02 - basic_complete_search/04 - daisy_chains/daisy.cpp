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
	ll n,tmp,sum,i,j;
	double avg;
	cin>>n;
	vector<ll> flowers;
	std::map<ll,ll> exists;
	for (size_t i = 0; i < n; i++)
	{
		cin>>tmp;
		flowers.push_back(tmp);
	}
	ll photos=0;
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			if(j==i){
				// cout<<"single\n";
				photos+=1;
			}
			else{
				//calculate avg
				sum=0;
				for (size_t k = i; k <= j; k++)
				{
					sum+=flowers[k];
					// cout<<flowers[k]<<"\t";
				}
				// cout<<"\n";
				avg=sum/((double)(j-i)+1);
				// cout<<i<<"\t"<<j<<"\n";
				// cout<<"\t"<<flowers[i]<<"\t"<<flowers[j]<<"\t"<<sum<<"\t"<<avg<<"\n";
				if(avg==floor(avg)){
					for (size_t k = i; k <=j; k++)
					{
						if(avg==flowers[k]){
							photos+=1;
							// cout<<"\t\t DETECTED "<<k<<"\n";
							break;		
						}
					}			 
				}
				else
				{
					// cout<<"\t\t REJECT\n";
				}	
			}
		}
	}
	// cout<<"\n";
	cout<<photos<<"\n";
	
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	solve();
	return 0;
}