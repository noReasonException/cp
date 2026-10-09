class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int> hashMap;
        for(int i=0;i<s.size();i++){
            if(!hashMap.contains(s[i])){
                hashMap[s[i]]=1;
            }
            else{
                hashMap[s[i]]++;
            }
        }
        int same=-1;
        for(auto [k,v]:hashMap){
            if(same==-1)same=v;
            else {
                if(v!=same)return false;
            }
        }
        return true;
    }
};