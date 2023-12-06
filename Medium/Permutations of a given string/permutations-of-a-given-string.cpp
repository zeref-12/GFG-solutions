//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		void solve(string S,vector<string> &ans,int index,bool flag){
		    if(index == S.size()){
		        for(auto x : ans){
		            if(x == S) flag =1;
		        }
		        if(flag == 0) ans.push_back(S);
		        return ;
		    }
		    
		    for(int i = index;i<S.size();i++){
		        swap(S[index],S[i]);
		        solve(S,ans,index+1,flag);
		        swap(S[index],S[i]);
		    }
		}
	
		vector<string>find_permutation(string S)
		{
		vector<string> ans;
// 		sort(S.begin(),S.end());
        solve(S,ans,0,0);
        return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends