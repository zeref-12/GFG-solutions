//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
   bool isPossible(int arr[],int n ,int k,long long int mid){
       long long int totalTime = 0;
       long long int painterCount = 1;
       
       for(long long int i =0;i<n;i++){
           if(arr[i] + totalTime <= mid){
               totalTime += arr[i];
           }
           else{
               painterCount++;
               if(painterCount > k || arr[i] > mid)
               return false;
               totalTime = arr[i];
           }
       }
      return true; 
   }
   
   
   
    long long int minTime(int arr[], int n, int k)
    {
        long long int s = 0,e,ans,sum = 0;
        
        for(long long int i =0;i<n;i++){
            sum += arr[i];
        }
        e = sum;
        
        while(s <= e){
            long long int mid = s + (e-s)/2;
            
            if(isPossible(arr,n,k,mid)){
                ans = mid;
                e = mid -1;
            }
            else{
                s = mid +1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends