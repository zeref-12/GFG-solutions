//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool check(int i,int sum,vector<int> arr,vector<vector<int>> &dp){
        if(sum == 0) return true;
        if(i == 0) return (sum == arr[i]);
        
        if(dp[i][sum] != -1) return dp[i][sum];
        bool not_take = check(i-1,sum,arr,dp);
        bool take = false;
        if(arr[i] <= sum){
            take = check(i-1,sum-arr[i],arr,dp);
        }
        
        return dp[i][sum] = take || not_take;
    }

    bool isSubsetSum(vector<int>arr, int sum){
       int n = arr.size();
       vector<vector<int>> dp(n,vector<int>(sum+1,-1));
       return check(n-1,sum,arr,dp); 
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends