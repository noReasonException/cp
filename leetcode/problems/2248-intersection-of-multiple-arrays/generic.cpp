class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int,int> hashMap;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                if(!hashMap.contains(nums[i][j])){
                    hashMap[nums[i][j]]=1;
                }
                else{
                    hashMap[nums[i][j]]++;
                }
            }
        }
        vector<int> ans;
        for(auto [k,v]:hashMap){
            cout<<k<<"\t"<<v<<"\n";
            if(v==nums.size()){
                ans.push_back(k);
            }
        }
        std::sort(ans.begin(),ans.end());
        return ans;
    }
};