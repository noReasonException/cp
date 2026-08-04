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

	bool exists_plain=false;
	bool exists_spotty=false;
	for (size_t i = 0; i < m; i++) //for every i position
	{
		for (size_t j = 0; j < m; j++)
		{
			for (size_t k = 0; k < m; k++)
			{
				exists_plain=false;
				exists_spotty=false;
				if(i==j||j==k||i==k) continue;
				set<pair<char,pair<char,char>>> plain_set;
				set<pair<char,pair<char,char>>> spotty_set;
				for (size_t l = 0; l < n; l++)
				{
					//load plain set
					plain_set.insert({plain[l][i],{plain[l][j],plain[l][k]}});
				}
				for (size_t l = 0; l < n; l++)
				{
					//load spotty set
					spotty_set.insert({spotty[l][i],{spotty[l][j],spotty[l][k]}});
					if(plain_set.find({spotty[l][i],{spotty[l][j],spotty[l][k]}})!=plain_set.end()){
						exists_plain=true;
					}
				}
				for(auto e:plain_set){
					if(spotty_set.find(e)!=spotty_set.end()){
						exists_spotty=true;
					}
				}
				
				if(!exists_plain&&!exists_spotty)ans+=1;
			}
			
		}
		
	}
	cout<<ans<<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// freopen("cownomics.in", "r", stdin);
	// freopen("cownomics.out", "w", stdout);

	solve();
	return 0;
}