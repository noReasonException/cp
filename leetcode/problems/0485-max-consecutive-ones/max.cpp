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

Given a binary array nums, return the maximum number of consecutive 1's in the array.

 

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2

 

Constraints:

    1 <= nums.length <= 105
    nums[i] is either 0 or 1.

*/
int longest_ones(vector<int>nums){
        int low=0,high=0,sizemax=0;
        while(low<nums.size()&&nums[low]==0)low+=1;
        high=low;
        while(high<nums.size()){
            if(high+1==nums.size()){
                sizemax=max(sizemax,high-low+1);
                break;
            }
            if(nums[high+1]==1)high++;
            else {
                sizemax=max(sizemax,high-low+1);
                low=high+1;
                while(low<nums.size()&&nums[low]==0){
                    low+=1;
                }
                high=low;
            }
        }
        return sizemax;
    
	
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);

	cout<<longest_ones({1,1,0,1,1,1});
	return 0;
}