class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> set;
        for(int i=0;i<nums.size();i++){
            set.insert(nums[i]);
        }
        for(int i=0;i<=nums.size();i++){
            if(!set.contains(i))return i;
        }
        return -1;
    }
};