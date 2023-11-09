//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

	vector<int> bracketNumbers(string S)
	{
	    vector<int> ans;
	    stack<int> sk;
	    int count = 0;
	    for(int i =0 ;i<S.size();i++)
	    {
	        if(S[i] == '(')
	        {
	            count++;
	            sk.push(count);
	            ans.push_back(count);
	        }
	        if(S[i] == ')')
	        {
	            ans.push_back(sk.top());
	            sk.pop();
	        }
	        
	    }
	   return ans; 
	}
};

//{ Driver Code Starts.

int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	string tc;
   	getline(cin, tc);
   	t = stoi(tc);
   	while(t--)
   	{
   		string s;
   		getline(cin, s);

   	    Solution ob;

   		vector<int> ans = ob.bracketNumbers(s);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends