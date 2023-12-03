//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
       long long MOD = 1000000007;
       int a = 0,b = 1,c = 0;
       if( n< 2) return n;
    
        for(int i =1;i<n;i++){
            c = a%MOD + b%MOD;
            a = b;
            b = c;
             
        }
        
        return c%MOD;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends