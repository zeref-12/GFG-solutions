//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isPossible(int arr[],int n ,int m , int mid){
        int pageSum = 0;
        int studentCount = 1;
        
        for(int i =0;i<n;i++){
            if(pageSum + arr[i] <= mid){
                pageSum += arr[i];
            }
            else{
                studentCount++;
                if(studentCount > m || arr[i] > mid) return false;
                pageSum = arr[i];
            }
        }
      return true;     
    }
    
    
    
    int findPages(int arr[], int n, int m) 
    {
        int s = 0;
        int sum = 0;
        int ans = -1;
        for(int i = 0;i<n;i++) sum += arr[i];
        
        int e = sum;
        
        while(s <= e){
            
            int mid = s + (e-s)/2;
            if(isPossible(arr,n,m,mid)){
                ans = mid;
                e = mid - 1; 
            }
            else{
                s = mid + 1;
            }
        }
        if(m>n) return -1;
     return ans;    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends