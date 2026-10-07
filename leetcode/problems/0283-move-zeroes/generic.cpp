#include <vector>
using namespace std;
class Solution {
public:
    /*
            l  h
        1   [0,1,0,3,12]
            l  h
        2   [1,0,0,3,12]
               l   h
        3   [1,0,0,3,12]

        4   [1,3,0,0,12]

        5   [1,3,12,0,0]
    
    */
    void moveZeroes(vector<int>& nums) {
        int swap,zero,nonZero;
        zero=0;
        nonZero=0;
        bool finished=false;
        int tries=0;
        for(int i=0;i<nums.size();i++){
            zero=0;
            nonZero=i;
            while(zero<nums.size()&&nums[zero]!=0)zero++;
            while(nonZero<nums.size()&&nums[nonZero]==0)nonZero++;
            // cout<<zero<<"\t"<<nonZero<<"\n";
            if(zero==nums.size()||nonZero==nums.size())break;
            if(zero<nonZero){
                
                nums[zero]=nums[nonZero];
                nums[nonZero]=0;
            }

        }
    }
};