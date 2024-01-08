//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void bfs(int x,int y,vector<vector<int>> &visited,vector<vector<char>>& grid){
    visited[x][y] = 1;
    queue<pair<int,int>> q;
    q.push({x,y});

    int row = grid.size();
    int col = grid[0].size();

    while(!q.empty()){
        int curr_row = q.front().first;
        int curr_col = q.front().second;
        q.pop();

        for(int row_range = -1; row_range <= 1; row_range++){
            for(int col_range = -1; col_range <= 1 ; col_range++){
                
                int new_row = curr_row + row_range;
                int new_col = curr_col + col_range;
                if(new_row >=0 && new_row < row && new_col >=0 && new_col < col
                && grid[new_row][new_col] == '1' && !visited[new_row][new_col]){
                  visited[new_row][new_col] = 1;
                  q.push({new_row,new_col});
                }
            }
        }
    }

   }
   
    int numIslands(vector<vector<char>>& grid) {
          int row = grid.size();
        int col = grid[0].size();

        int count = 0;
        vector<vector<int>> visited(row,vector<int>(col,0));

        for(int i = 0 ; i < row; i++){
            for(int j = 0; j < col ;j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    count++;
                    bfs(i,j,visited,grid);
                }
            }
        }
       return count; 
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends