class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k){
        int m=grid.size();
        int n=grid[0].size();
        int MOD=1e9+7;
        vector<vector<vector<long long>>>dp(m,vector<vector<long long>>(n,vector<long long>(k,0)));
        dp[0][0][grid[0][0]%k]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int r=0;r<k;r++){
                    // k+r-grid[0][0]%k;
                    if(i>0 && j>0){
                      dp[i][j][r]=(dp[i-1][j][(k+r-grid[i][j]%k)%k]+dp[i][j-1][(k+r-grid[i][j]%k)%k])%MOD;
                    }else if(i>0 && j==0){
                          dp[i][j][r]=(dp[i-1][j][(k+r-grid[i][j]%k)%k])%MOD;
                    }else if(i==0 && j>0){
                        dp[i][j][r]=(dp[i][j-1][(k+r-grid[i][j]%k)%k])%MOD;
                    }
                }
            }
        }
        return dp[m-1][n-1][0];
    }
};