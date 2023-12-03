//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<long long> Series(int N) {
        vector<long long> ans;
        long long a = 0,b = 1,c = 0;
       if(N < 2) return {N-1,N};
        ans.push_back(0);
        ans.push_back(1);
       
        for(int i =1;i<N;i++){
            c = a + b;
            a = b;
            b = c;
            ans.push_back(c); 
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<long long> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends