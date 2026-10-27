class Solution {
public:
bool isValid(int i,int j,int m,int n){
    return i>=0 && j>=0 && i<m && j<n;
}
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&vis){
        int m=grid.size();
        int n=grid[0].size();
        vis[i][j]=1;
        vector<pair<int,int>>movements={{1,0},{-1,0},{0,1},{0,-1}};
        for(auto move:movements){
            int x=i+move.first;
            int y=j+move.second;
        if(isValid(x,y,m,n)){

                if(!vis[x][y] && grid[x][y]==0){
                    vis[x][y]=1;
                    dfs(x,y,grid,vis);
                }
            }
        }
    }
    void dfs2(int i,int j,vector<vector<int>>&grid){
        int m=grid.size();
        int n=grid[0].size();
        // vis[i][j]=1;
        grid[i][j]=1;
        vector<pair<int,int>>movements={{1,0},{-1,0},{0,1},{0,-1}};
        for(auto move:movements){
            int x=i+move.first;
            int y=j+move.second;
        if(isValid(x,y,m,n)){

                if(grid[x][y]==0){
                    // vis[x][y]=1;
                    grid[x][y]=1;
                    dfs2(x,y,grid);
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            if(grid[i][0]==0){
                dfs2(i,0,grid);
            }
        }
        for(int i=0;i<m;i++){
            if(grid[i][n-1]==0){
                dfs2(i,n-1,grid);
            }
        }
        for(int j=0;j<n;j++){
            if(grid[0][j]==0){
                dfs2(0,j,grid);
            }
        }
        for(int j=0;j<n;j++){
            if(grid[m-1][j]==0){
                dfs2(m-1,j,grid);
            }
        }
     
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 && !vis[i][j]){
                    dfs(i,j,grid,vis);
                    ans++;
                }
            }
        }      
        return ans; 
    }
};