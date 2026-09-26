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
int solve(vector<int> nums){
	//build prefix sum
	//query for every i,i+1
	//if yes, increase counter

	//prefix sum
	int prefix=0;
	int answer=0;
	vector<int>prefix_sum;
	for(int i=0;i<nums.size();i++){
		prefix+=nums[i];
		prefix_sum.push_back(prefix);
	}
	// prefix sum passes test
	for (size_t i = 0; i < nums.size(); i++)
	{
		cout<<prefix_sum[i]<<"\t";
	}
	cout<<"\n";

	//query for every
	//2 segments
	//	start i
	//	i+1 end
	for (int i = 0; i < prefix_sum.size()-1; i++)
	{
		int segmentA = prefix_sum[i];
		int segmentB = prefix_sum[prefix_sum.size()-1]-prefix_sum[i];
		if(segmentA>segmentB){
			cout<<segmentA<<"\t"<<segmentB<<"\n";
			answer++;
		}
	}
	return answer;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout<<solve({10,4,-8,7})<<"\n";
	return 0;
}