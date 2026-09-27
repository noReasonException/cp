
#include <string>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int low=0,high=0,lowcurr=0,highcurr=0;
        char swap;
        while(high<s.size()){
            // cout<<high<<"\n";
            if(high<s.size()&&s[high]!=' ')high++;
            else{
                //reverse word
                //from low to high-1, high is whitespace
                high--;
                //now from low to high
                lowcurr=low;
                highcurr=high;
                while(lowcurr<=highcurr){
                    swap = s[lowcurr];
                    s[lowcurr]=s[highcurr];
                    s[highcurr]=swap;
                    lowcurr++;
                    highcurr--;
                }
                //reset low, reset high
                high+=2;
                low=high;
            }
        }
        lowcurr=low;
        highcurr=high-1;
        while(lowcurr<highcurr){
            swap = s[lowcurr];
            s[lowcurr]=s[highcurr];
            s[highcurr]=swap;
            lowcurr++;
            highcurr--;
        }
        return s;
    }
};