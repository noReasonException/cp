#include<vector>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int prefix=0;
        int segmentA,segmentB;
        vector<int>prefix_sum;
        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            prefix_sum.push_back(prefix);
        }
        for(int i=0;i<nums.size();i++){
            segmentA = i>0?prefix_sum[i-1]:0;
            segmentB = (i<nums.size()-1)?(prefix_sum[prefix_sum.size()-1]-prefix_sum[i]):0;
            // cout<<i<<"\n";
            // cout<<"\tsegmentA\t"<<segmentA<<" segmentB\t"<<segmentB<<"\n";
            if(segmentA==segmentB)return i;
        }

        return -1;
    }
};