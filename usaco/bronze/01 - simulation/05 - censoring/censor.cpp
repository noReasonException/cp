#include <iostream>
#include <vector>
#include <set>
#include <math.h>
using namespace std;
#define ll 		long long
#define ull 	unsigned long long
#define ld 		long double
#define MOD  	pow(10,9)+7;
#define INF_INT	(1<<30)
#define INF_LL 	(1L<<62)

//forward refs
template <typename container> void debug(container& genericSequence,string id="None", int depth=0);

//debug utils
#ifdef DEBUG
	template <typename container> void debug(container& genericSequence,string id, int depth){
		cout<<"=============Debug ("<<id<<") START =============\n";
		string prefix = "";
		for(int i=0;i<depth;i++) prefix+="\t";

		for(auto every: genericSequence){
			cout<<prefix<<every<<"\n";
		}
		cout<<"=============Debug ("<<id<<") END =============\n";

	}
#endif
#ifndef DEBUG
	template <typename container> void debug(container& genericSequence,string id, int depth){
		return ;
	}

#endif

/**
 	*
	? Stuff to look for ->
    * stay organised
    * int overflows, array bounds, etc.
    * special cases (n=1)?
    * do something instead of nothing
    * timebox your approach
    * simple is better than complex
    * n % mod = (n % mod + mod) % mod;
    * long long instead of int
    
*/
void solve(){
	std::string s,t,o;
	cin>>s;
	cin>>t;
	o=s;
	bool start_flag=false;
	int s_index=0,t_index=0;
	while(s_index<s.size()){
		// cout<<s_index<<"-"<<s[s_index]<<"\n";
		//not started and first character matches
		if(!start_flag && s[s_index]==t[t_index]){
			// cout<<"\tStarted matching\t"<<s[s_index]<<"="<<t[t_index]<<"\n";
			start_flag=true;
			t_index++;
			s_index++;
			
		}
		//started and this character matches
		else if(start_flag && s[s_index]==t[t_index]){
			// cout<<"\tContinue matching\t"<<s[s_index]<<"="<<t[t_index]<<"\n";
			t_index++;
			s_index++;
			
		}
		//started and this character does not match, we havent finished
		else if(start_flag && s[s_index]!=t[t_index] && t_index<t.size()){
			// cout<<"\tEarly break\t\t"<<s[s_index]<<"!="<<t[t_index]<<"\n";
			start_flag=false;
			s_index-=t_index-1;
			t_index=0;
		}
		//started and this character does not match, we have finished however matching chars
		else if(start_flag && s[s_index]!=t[t_index] && t_index==t.size()){
			// cout<<"\tTotal match\t"<<s[s_index]<<"!="<<t[t_index]<<"\n";
			start_flag=false;
			s_index-=t_index; //go back
			s=s.erase(s_index,t_index);
			s_index=max(0,s_index-100);
			t_index=0;
			
			
		}
		else{
			s_index++;
		}
	}
	// cout<<o<<"\n";
	cout<<s<<"\n";
	// cout<<t<<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("censor.in", "r", stdin);
	freopen("censor.out", "w", stdout);
	solve();
	return 0;
}