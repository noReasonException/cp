#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <array>
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
	std::string p ;
	int pairs=0;
	int  index=0,index_in=0;
	int k;
	std::array<int,26> letters = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	cin>>p;
	for (size_t i = 0; i < p.size(); i++)
	{
		index = p[i]-'A';
		// cout<<((char)p[i])<<'\t'<<index<<"\n";
		if(letters[index]==0){
			//its now opening
			letters[index]=1;
		}
		else if(letters[index]==1){
			letters[index]=2; //closed
			//detect the index of the opening
			for (size_t j = 0; j < i; j++)
			{
				if(p[i]==p[j])k=j;
			}
			//check open between those indexes
			for (size_t l = k; l < i; l++)
			{
				index_in=p[l]-'A';
				if(letters[index_in]==1){
					//cout<<p[i]<<" crosses with "<<p[l];
					pairs+=1;
				}
			}
			


			
		}
		// for (size_t k = 0; k < 26; k++)
		// {
		// 	cout<<letters[k]<<" ";
		// }
		// cout<<"\n";
		
	}
	cout<<pairs<<"\n";
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("circlecross.in", "r", stdin);
	freopen("circlecross.out", "w", stdout);
	solve();
	return 0;
}