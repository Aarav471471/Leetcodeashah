class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();
        vector<vector<int>>dp(m,vector<int>(n,INT_MAX));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1){
                    if(dungeon[i][j]<=0){
                        dp[i][j]=abs(dungeon[i][j])+1;
                    }else{
                        dp[i][j]=1;
                    }
                }else if(i==m-1){
                    if(dungeon[i][j]<=0){
                        dp[i][j]=dp[i][j+1]-dungeon[i][j];
                    }else{
                        dp[i][j]=max(1,dp[i][j+1]-dungeon[i][j]);
                    }
                }else if(j==n-1){
                    if(dungeon[i][j]<=0){
                        dp[i][j]=dp[i+1][j]-dungeon[i][j];
                    }else{
                        dp[i][j]=max(1,dp[i+1][j]-dungeon[i][j]);
                    }
                }else{
                    if(dungeon[i][j]<=0){
                        dp[i][j]=min(dp[i][j+1],dp[i+1][j])-dungeon[i][j];
                    }else{
                        dp[i][j]=max(1,min(dp[i][j+1],dp[i+1][j])-dungeon[i][j]);
                    }
                }
            }
        }
        return dp[0][0];
    }
};