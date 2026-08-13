#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
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
vector<vector<ll>> apple_pics;
void combinations(vector<ll>&all,ll k,ll depth,vector<ll>&arr){
	if(arr.size()==k){
		apple_pics.push_back(arr);
	}
	else{
		for (ll i = depth; i < all.size(); i++)
		{
			arr.push_back(all[i]);
			combinations(all,k,i+1,arr);
			arr.pop_back();
		}
	}
}


void solve(){
	ll n,a;
	cin>>n;
	vector<ll> apples;
	ll min_diff=INF_LL;
	for (ll i = 0; i < n; i++)
	{
		cin>>a;
		apples.push_back(a);
	}
	vector<ll>arr;
	//load pics array
	for (ll i = 1; i <= n; i++)
	{
		combinations(apples,i,0,arr);
	}

	for (size_t i = 0; i < apple_pics.size(); i++)
	{
		for (size_t j = 0; j < apple_pics[i].size(); j++)
		{
			cout<<apple_pics[i][j]<<",";
		}
		cout<<"\n";
		
	}
	
	for(auto first_basket:apple_pics){
		//weight of first basket = each
		//weight of second basket, whomever dont exist in the first basket
		vector<ll> second_basket;
		
		//εδω ειναι το λαθος, εχει duplicates!
		for(auto each_element:apples){
			if(std::find(first_basket.begin(),first_basket.end(),each_element)==first_basket.end()){
				second_basket.push_back(each_element);	
			}
		}
		//now we have 2 baskets, lets find their difference
		ll sum1=0, sum2=0;
		for (ll i = 0; i < first_basket.size(); i++)
		{
			sum1+=first_basket[i];
		}
		for (ll i = 0; i < second_basket.size(); i++)
		{
			sum2+=second_basket[i];
		}
		if(abs(sum1-sum2)<min_diff)min_diff=abs(sum1-sum2);
	}

	cout<<min_diff<<"\n";
	
}

	
	
	
// }


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);

	solve();
	return 0;
}