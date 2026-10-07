class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> set;
        for(int i=0;i<s.size();i++){
            if(set.contains(s[i]))return s[i];
            else set.insert(s[i]);
        }
        return 'c';
    }
};