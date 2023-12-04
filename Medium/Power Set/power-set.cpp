//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		void solve(string s,vector<string> &ans,string subset,int index){
		    if(index == s.size()){
		        if(!subset.empty())
		        ans.push_back(subset);
		        return ;
		    }
		    subset += (s[index]);
		    solve(s,ans,subset,index+1);
		    subset.pop_back();
		    solve(s,ans,subset,index+1);
		}
		
		
		vector<string> AllPossibleStrings(string s){
		    vector<string> ans;
		    string subset = "";
		    solve(s,ans,subset,0);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends