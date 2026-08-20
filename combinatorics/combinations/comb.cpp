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

/**
 * 	1. Given an integer 1 <= n <= 20, write a recursive algorithm that prints all the combinations of the set {1,2,3,...,n}.
 * Combinations = Order DOES NOT matter
 */


void print_instance(vector<int> used){
	for(auto a:used){
		cout<<a<<",";
	}
	cout<<"\n";
}
void combination(vector<int>&available,int r,int depth,vector<int>& used){
	if(used.size()==r){
		print_instance(used);
	}
	else for (size_t i = depth; i < available.size(); i++)
	{
		used.push_back(available[i]);
		combination(available,r,i+1,used);
		used.pop_back();
	}
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	vector<int>available={1,2,3,4};
	vector<int>used={};
	int r=4;
	combination(available,r,0,used);

	return 0;
}