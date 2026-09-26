#include <vector>
using namespace std;
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> runningSum;
        int curr=0;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            runningSum.push_back(curr);
        }
        return runningSum;
    }
};