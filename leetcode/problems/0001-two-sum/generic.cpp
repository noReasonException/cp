#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //number,index
        unordered_map<int,int> hashmap;
        int n=nums.size();
        int a,b;
        for(int i=0;i<n;i++){
            hashmap[nums[i]]=i;
        }
        for(int i=0;i<n;i++){
            a=nums[i];
            b=target-a;
            if(hashmap.contains(b)&&hashmap[b]!=i){
                return {i,hashmap[b]};
            }
        }
        return {-1,-1};
    }
};