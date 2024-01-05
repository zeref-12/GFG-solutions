//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node,vector<int> adjlist[],vector<int> &visited){
        visited[node] = 1;
        for(auto x : adjlist[node]){
            if(!visited[x]){
                dfs(x,adjlist,visited);
            }
        }
      
    }
    
    
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adjlist[V];
        
        for(int i = 0 ; i < V ; i++){
            for(int j = 0 ; j < V; j++){
                if(adj[i][j] == 1 && i != j){
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        
        vector<int> visited(V,0);
        int ans = 0;
        
        for(int i = 0 ; i < V; i++){
            if(!visited[i]){
                ans++;
                dfs(i,adjlist,visited);
            }
        }
    return ans;    
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends