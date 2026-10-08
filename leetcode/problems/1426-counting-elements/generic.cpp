class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> set;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            set.insert(arr[i]);
        }
        for(int i=0;i<arr.size();i++){
            if(set.contains(arr[i]+1))ans++;
        }
        return ans;

    }
};