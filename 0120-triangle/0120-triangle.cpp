class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        dp[0][0]=triangle[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<triangle[i].size();j++){
                if(j==0){
                    dp[i][j]=triangle[i][j]+min(dp[i][j],dp[i-1][j]);
                }else if(j==n-1){
                    dp[i][j]=triangle[i][j]+min(dp[i][j],dp[i-1][j-1]);
                }else{
                    dp[i][j]=triangle[i][j]+min({dp[i][j],dp[i-1][j],dp[i-1][j-1]});
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }
};