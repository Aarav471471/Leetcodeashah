class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<vector<int>>>>dp(m,vector<vector<vector<int>>>(n,vector<vector<int>>(m,vector<int>(n,-1*(INT_MAX)))));
        dp[0][0][0][0]=grid[0][0];


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<m;k++){
                    for(int l=0;l<n;l++){
                        // if(i!=0 && j!=0 && k!=0 && l!=0){
                        //     dp[i][j][k][l]=max({dp[i-1][j][k-1][l],dp[i-1][j][k][l-1],dp[i][j-1][k-1][l],dp[i][j-1][k][l-1]})+matrix[0][0];   
                        // }
                         if(grid[i][j]==-1 || grid[k][l]==-1){continue;}
                        if(i==0 && j==0 && k==0 && l==0){continue;}
                        if(i>0 && k>0){
                            dp[i][j][k][l]=max(dp[i-1][j][k-1][l],dp[i][j][k][l]);
                        }
                        if(i>0 && l>0){
                            dp[i][j][k][l]=max(dp[i-1][j][k][l-1],dp[i][j][k][l]);
                        }
                        if(j>0 && k>0){
                            dp[i][j][k][l]=max(dp[i][j-1][k-1][l],dp[i][j][k][l]);
                        }
                        if(j>0 && l>0){
                            dp[i][j][k][l]=max(dp[i][j-1][k][l-1],dp[i][j][k][l]);
                        }
                        if(dp[i][j][k][l]==-1*(INT_MAX)){
                            continue;
                        }
                        if(i==k && j==l){
                            dp[i][j][k][l]+=grid[i][j];
                        }else{
                            dp[i][j][k][l]+=grid[i][j]+grid[k][l];
                        }
                    }
                }
            }
        }
        if(dp[m-1][n-1][m-1][n-1]<=0){
            return 0;
        }
        return dp[m-1][n-1][m-1][n-1];
    }
};