//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string s, int k) {
       
       stack<char>st;
       string ans="";
       
       for( auto c: s){
           
           while(!st.empty() && k!=0 && st.top()>c){
               st.pop();
               k--;
           }
           if(st.empty() && c == '0') continue;
           st.push(c);
       }
       while(!st.empty() && k!=0)
       {
           st.pop();k--;
       }
       if(st.empty()) return "0";
       
       while(!st.empty())
       {
          ans+=st.top();
          st.pop();
       }
       reverse(ans.begin(),ans.end());
       
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends