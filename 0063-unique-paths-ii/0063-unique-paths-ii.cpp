class Solution {
public:
    vector<vector<int>>dp;
    int ways(int i,int j,vector<vector<int>>& obstacleGrid,int m,int n){
        if(i==m-1 && j==n-1 && obstacleGrid[i][j]==0){return 1;}
        if(i>=m || j>=n || obstacleGrid[i][j]==1){return 0;}
        if(dp[i][j]!=-1){return dp[i][j];}
        int ans=0;
        ans=ways(i+1,j,obstacleGrid,m,n)+ways(i,j+1,obstacleGrid,m,n);
        return dp[i][j]=ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        dp.assign(m+1,vector<int>(n+1,-1));
        return ways(0,0,obstacleGrid,m,n);
    }
};