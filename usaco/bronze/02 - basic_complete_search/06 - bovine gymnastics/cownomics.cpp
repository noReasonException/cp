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
	int n,m,ans=0;
	cin>>n>>m;
	string tmp;
	vector<string> spotty;
	vector<string> plain;

	for (size_t i = 0; i < n; i++)
	{
		cin>>tmp;
		spotty.push_back(tmp);
	}

	for (size_t i = 0; i < n; i++)
	{
		cin>>tmp;
		plain.push_back(tmp);
	}

	// for (size_t i = 0; i < n; i++)
	// {
	// 	cout<<spotty[i]<<"\n";
	// }
	// for (size_t i = 0; i < n; i++)
	// {
	// 	cout<<plain[i]<<"\n";
	// }


	for (size_t i = 0; i < m; i++) //for every position
	{
		//all plain cows need to have this 
		set<char> factorsPlain;
		set<char> factorsSpotty;
		bool exists_factor_in_spotty=false;
		bool exists_factor_in_plain=false;
		for (size_t j = 0; j < n; j++)
		{
			factorsPlain.insert(plain[j][i]);
		}
		if(factorsPlain.size()==4) continue;
		for (size_t j = 0; j < n; j++)
		{
			factorsSpotty.insert(spotty[j][i]);
			if(factorsPlain.find(spotty[j][i])!=factorsPlain.end()){
				exists_factor_in_spotty=true;
			}
		}
		if(factorsSpotty.size()==4) continue;
		for (size_t j = 0; j < n; j++)
		{
			if(factorsSpotty.find(plain[j][i])!=factorsSpotty.end()){
				exists_factor_in_plain=true;
			}
		}
		if(!exists_factor_in_spotty||!exists_factor_in_plain)ans+=1;	
	}
	cout<<ans<<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout);

	solve();
	return 0;
}