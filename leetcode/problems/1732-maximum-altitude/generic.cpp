#include <vector>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int prefix=0;
        int max_prefix=0;
        for(int i=0;i<gain.size();i++){
            prefix+=gain[i];
            max_prefix=max(max_prefix,prefix);
            
        }
        return max_prefix;
    }
};