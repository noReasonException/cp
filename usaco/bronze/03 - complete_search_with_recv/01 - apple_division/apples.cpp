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
	ll n,c;
	cin>>n;
	vector<ll> apples;
	for (ll i = 0; i < n; i++)
	{
		cin>>c;
		apples.push_back(c);
	}

	// cout<<"Testcase\n";
	// for (size_t i = 0; i < n; i++)
	// {
	// 	cout<<apples[i]<<"\t";
	// }
	// cout<<"\n";

	/**
	 * To generate subsets of n elements, you need a number with n digits
	 * for 0 elements, there is no subset
	 * for 1 element, 1 is a good candidate
	 * for 2 elements, you need 00,01,10,11 => 4
	 * for 3 elements , you need 000,001...111 => 8
	 * for n elements, you need 2^n
	 * 
	 */
	ll k = pow(2,n);
	ll position=0;
	ll suma,sumb;
	ll diff=0,min_diff=INF_INT;
	vector<ll> subsetIndexes;
	vector<ll> bucketA,bucketB;
	for (ll i = 0; i < k; i++)
	{	//each number is a subset
		position=0;
		subsetIndexes.clear();
		for (ll j = i; j>0; j=j>>1)
		{
			position+=1;
			// cout<<(j&1)<<"\t";
			subsetIndexes.push_back(j&1);
		}	
		for (;position<n;position++)
		{
			// cout<<0<<"\t";
			subsetIndexes.push_back(0);
		}
		

		bucketA.clear();
		bucketB.clear();

		for (ll i = 0; i < subsetIndexes.size(); i++)
		{
			if(subsetIndexes[i]){
				bucketA.push_back(apples[i]);
			}
			else{ 
				bucketB.push_back(apples[i]);
			}
		}
		suma=0;
		sumb=0;
		for(auto each:bucketA){
			// cout<<"\t BUCK-A\t"<<each;
			suma+=each;
		}
		for(auto each:bucketB){
			// cout<<"\t BUCK-B\t"<<each;
			sumb+=each;
		}

		diff = abs(suma-sumb);
		if(diff<min_diff)min_diff=diff;
		// cout<<"\n";
	}
	cout<<min_diff<<"\n";
	


	
	// int l = 0b1000;

	// cout<<"\t"<<l<<"\n";
	
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	solve();
	return 0;
}