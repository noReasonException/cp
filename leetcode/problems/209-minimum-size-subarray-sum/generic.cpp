#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        long long low=0;
        long long currSize=0;
        long long ans = nums.size()+1;
        long long currSum=0;
        long long flag=0;
        for(long long high=0;high<nums.size();high++){
            
            currSum+=nums[high];
            // cout<<low<<"\t"<<high<<"\t"<<currSum<<"\n";
            if(currSum>=target){
                flag=1;
                ans=min(ans,high-low+1);
                // cout<<"valid window 1!\n";  
                // cout<<"\t"<<low<<"\t"<<high<<"\t"<<currSum<<"\t"<<high-low+1<<"\n";
            }
            while(low<high&&currSum-nums[low]>=target){
                flag=1;
                currSum-=nums[low];
                low++;
                
                ans=min(ans,high-low+1);
                // cout<<"valid reduce 2!\n"; 
                // cout<<"\t"<<low<<"\t"<<high<<"\t"<<currSum<<"\t"<<high-low+1<<"\n";
            }
        }
        return flag?ans:0;
    }
};