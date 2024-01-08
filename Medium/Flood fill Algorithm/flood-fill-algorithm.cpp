//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int x,int y,vector<vector<int>> &visited,vector<vector<int>>& image,int color,int trigger){
        visited[x][y] = 1;
        image[x][y] = color;
        int m = image.size();
        int n = image[0].size();

        int row_dec[] = {-1, 0, 1, 0};
        int col_dec[] = { 0, 1, 0, -1};

        for(int i = 0 ; i < 4 ; i++){
            int new_row = x + row_dec[i];
            int new_col = y + col_dec[i];

            if(new_row >= 0 && new_row < m && new_col >= 0 && new_col < n 
            && !visited[new_row][new_col] && image[new_row][new_col] == trigger){
                dfs(new_row,new_col,visited,image,color,trigger);
            }
        }
      
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        vector<vector<int>> visited(m,vector<int>(n,0));
        int trigger = image[sr][sc];
        dfs(sr,sc,visited,image,color,trigger);

      return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends