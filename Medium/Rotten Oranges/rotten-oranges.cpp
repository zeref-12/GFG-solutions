//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0, fresh = 0;
        queue<pair<int,int>> q;

        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0 ; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int dr[] = {-1,0,1,0};
        int dc[] = { 0,1,0,-1};

        while(!q.empty() && fresh > 0){

            int size = q.size();
            for(int i = 0 ; i < size; i++){
                auto temp = q.front();
                q.pop();

                for(int i = 0; i < 4; i++){
                    int x = temp.first + dr[i];
                    int y = temp.second + dc[i];

                    if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1){
                        grid[x][y] = 2;
                        q.push({x,y});
                        fresh--;
                    }
                }
            }time++;
        }
     return fresh == 0 ? time : -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends