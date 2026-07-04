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
	std::vector<std::pair<std::string,std::string>> cards;
	std::array<int,26> min_letters = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int n;
	std::string a,b;
	cin>>n;
	for (size_t i = 0; i < n; i++)
	{
		cin>>a>>b;
		cards.push_back(std::make_pair(a,b));
	}
	// for (size_t i = 0; i < n; i++)
	// {
	// 	cout<<cards[i].first<<" - "<<cards[i].second<<"\n";
	// }

	for (size_t i = 0; i < n; i++){
		std::array<int,26> max_letters_first = 	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		std::array<int,26> max_letters_second =	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		std::array<int,26> max_letters_final = 	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		// cout<<cards[i].first<<" - "<<cards[i].second<<"\n";
		// cout<<"=========================== AA ============================="<<i<<"\n";
		for (size_t j = 0; j < cards[i].first.size()/*max 10 */; j++){
			
			max_letters_first[(int)(cards[i].first[j] - 'a')]+=1;
			// cout<<"\t";
			// for (size_t j = 0; j < 26; j++){	
			// 	cout<<(char)('a'+j)<<" ";
			// }
			// cout<<"\n";
			// cout<<"\t";
			// for (size_t j = 0; j < 26; j++){	
			// 	cout<<max_letters_first[j]<<" ";
			// }
			// cout<<"\n";
		}
		for (size_t j = 0; j < cards[i].second.size()/*max 10 */; j++){ 
			max_letters_second[(int)(cards[i].second[j] - 'a')]+=1;
			// cout<<"\t";
			// for (size_t j = 0; j < 26; j++){	
			// 	cout<<(char)('a'+j)<<" ";
			// }
			// cout<<"\n";
			// cout<<"\t";
			// for (size_t j = 0; j < 26; j++){	
			// 	cout<<max_letters_second[j]<<" ";
			// }
			// cout<<"\n";
		}
		// cout<<"=========================== BB ============================="<<i<<"\n";
		
		for (size_t j = 0; j < 26; j++){	
			if(max_letters_first[j]>max_letters_final[j]) max_letters_final[j] = max_letters_first[j];
			if(max_letters_second[j]>max_letters_final[j]) max_letters_final[j] = max_letters_second[j];
			min_letters[j]+=max_letters_final[j];
		}
		// for (size_t j = 0; j < 26; j++){	
		// 	cout<<(char)('a'+j)<<" ";
		// }
		// cout<<"\n";
		// for (size_t j = 0; j < 26; j++){	
		// 	cout<<max_letters_first[j]<<" ";
		// }
		// cout<<"\n";
		// for (size_t j = 0; j < 26; j++){	
		// 	cout<<max_letters_second[j]<<" ";
		// }
		// cout<<"\n";
		// for (size_t j = 0; j < 26; j++){	
		// 	cout<<max_letters_final[j]<<" ";
		// }
		// cout<<"\n";
		// for (size_t j = 0; j < 26; j++){	
		// 	cout<<min_letters[j]<<" ";
		// }
		// cout<<"\n";
	}

	// for (size_t i = 0; i < n; i++)
	// {
	// 	cout<<cards[i].first<<" - "<<cards[i].second<<"\n";
	// }
	for (size_t i = 0; i < 26; i++)
	{
		cout<</*((char)('a'+i))<<"-"<<*/min_letters[i]<<'\n';
	}
	
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("blocks.in", "r", stdin);
	freopen("blocks.out", "w", stdout);
	solve();
	return 0;
}