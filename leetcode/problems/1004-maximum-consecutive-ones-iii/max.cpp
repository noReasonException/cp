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

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Constraints:
    1 <= nums.length <= 105
    nums[i] is either 0 or 1.
    0 <= k <= nums.length


*/
int longest_ones(vector<int>nums,int k){
	if(k==0){
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
    int low=0,high=0,zeroesWithin=0;
	int sizemax=-1;
	//initialization state
	while(low+1<nums.size()&&nums[low]==0)low++;
	high=low;
    if(high==nums.size()-1&&nums[high]==0)return k;
	while(zeroesWithin<k&&low-1>=0&&nums[low-1]==0){
		zeroesWithin++;
		low--;
	}
	// if(nums[low]==0)zeroesWithin=1;


	cout<<"low\thigh\tmove\n";
	while(low<=high&&high<nums.size()){
		cout<<low<<"\t"<<high<<"";
		if(high+1<nums.size()){

			if(nums[high+1]==1){
				cout<<"\t1\n";
				high++;
			}

			else if(nums[high+1]==0&&zeroesWithin<k){
				cout<<"\t2\n";
				high++;
				zeroesWithin++;
			}
			else if(nums[high+1]==0&&zeroesWithin>=k){
				//we cant move high at all, can we move low?
				if(nums[low]==0&&nums[low+1]==1){
					cout<<"\t3\n";
					low++;
					zeroesWithin--;
				}
				else if(nums[low]==0&&nums[low+1]==0){
					cout<<"\t4\n";
					low++;
					zeroesWithin--;
				}
				else if (nums[low]==1&&nums[low+1]==0){
					cout<<"\t5\n";
					low++;
				}
				else if (nums[low]==1&&nums[low+1]==1){
					cout<<"\t6\n";
					low++;
				}
				else cout<<"\tImpossible\n";

			}
			
		}
		else{
			sizemax=max(sizemax,high-low+1);
			cout<<"\tbreak\n";
			break;
		}
		sizemax=max(sizemax,high-low+1);
		
	
	}
	return sizemax;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	return 0;
}

