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
 * 
 * Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]

 

Constraints:

    1 <= nums.length <= 104
    -104 <= nums[i] <= 104
    nums is sorted in non-decreasing order.

 
Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?
 */
std::vector<int> squares(std::vector<int> input){
	std::vector<int> answer;
	if(input.size()>4){
		int firstNonNegative,l1,h1,l2,h2;
		firstNonNegative=0;
		while(firstNonNegative<input.size()&&input[firstNonNegative]<0)firstNonNegative++;
		l1=0;
		h1=firstNonNegative-1;
		l2=firstNonNegative;
		h2=input.size()-1;

		cout<<l1<<"-"<<h1<<"-"<<l2<<"-"<<h2<<"\n";
		if(firstNonNegative==input.size()){
			for (int i = (int)input.size()-1; i >=0; i--)
			{
				answer.push_back(input[i]*input[i]);
			}
			
		}
		else if(firstNonNegative==0){
			for (int i = 0; i < input.size(); i++)
			{
				answer.push_back(input[i]*input[i]);
			}
			
		}
		else if(l1<=h1&&l2<=h2&&h1<l2){
			//pow2-all
			for (int i = 0; i < input.size(); i++)
			{
				input[i] = (input[i]*input[i]);
			}
			while(h1>=l1&&l2<=h2){
				if(input[h1]<input[l2]){
					answer.push_back(input[h1]);
					h1--;
				}
				else{
					answer.push_back(input[l2]);
					l2++;
				}
			}
			if(h1>=l1){
				for (int i = h1; i >=l1; i--)
				{
					answer.push_back(input[i]);
				}	
			}
			if(l2<=h2){
				for (int i = l2; i <= h2; i++)
				{
					answer.push_back(input[i]);
				}
				
			}
		}
		else{
			cout<<"impossible";
		}

	}
	else{
		for (int i = 0; i < input.size(); i++)
		{
			input[i] = (input[i]*input[i]);
		}
		std::sort(input.begin(),input.end());
		for (size_t i = 0; i < input.size(); i++)
		{
			answer.push_back(input[i]);
		}
		
	}
	

	return answer;

	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	// std::vector<int> a  = {-4,-2,-1,0,1,2,3,6,8};
	// std::vector<int> a  = {-4,-2,-1,0,1,2};
	// std::vector<int> a  = {-5,-4,-3,-2,-1};
	// std::vector<int> a  = {1,2,3,4,5};
	// std::vector<int> a  = {-4,-1,0,3,10};
	std::vector<int> a  = {-5,0,1,1,2};
	std::vector<int>b = squares(a);
	// cout<<"\n";
	for (int i = 0; i < b.size(); i++)
	{
		cout<<b[i]<<"\t";
	}
	cout<<"\n";
	
	return 0;
}