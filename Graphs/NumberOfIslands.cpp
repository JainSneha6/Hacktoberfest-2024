class Solution {
private:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j]=1;
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        for(int k=0;k<4;k++){
            int ni = i + dir[k][0];
            int nj = j + dir[k][1];
            if(ni>=0 && ni<n && nj>=0 && nj<m && !vis[ni][nj] && grid[ni][nj]=='1'){
                dfs(grid,vis,ni,nj);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    count++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return count;
    }
};
