#include<vector>
using namespace std;
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k==0){
            return nums;
        }
        //make prefix sum
        long long prefix=0;
        vector<long long> prefix_sum;
        vector<int> result;
        for(long long i=0;i<nums.size();i++){
            prefix+=nums[i];
            prefix_sum.push_back(prefix);
        }
        //prefix sum passes tests
        // for(int i=0;i<prefix_sum.size();i++){
        //     cout<<prefix_sum[i]<<"\t";
        // }
        // cout<<"\n";
        long long avg;
        for(long long i=0;i<nums.size();i++){
            if(i-k<0||i+k>nums.size()-1)result.push_back(-1);
            else {
                // long long start = i-k==0?0:prefix_sum[i-k-1];
                // long long end = prefix_sum[i+k];
                // long long sum = end-start;
                // long long avg = sum/(2*k+1);
                avg = ((prefix_sum[i+k])-((i-k==0?0:prefix_sum[i-k-1])))/(2*k+1);
                result.push_back(avg);
                // cout<<start<<"\t"<<end<<"\t"<<sum<<"\t"<<avg<<"\n";
            }
        }

        return result;
    }
};