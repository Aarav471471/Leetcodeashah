class Solution {
public:
    int climbStairs(int n, vector<int>& cost) {
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            if(i>2){
                dp[i]=min(dp[i],dp[i-1]+cost[i-1]+1);
                dp[i]=min(dp[i],dp[i-2]+cost[i-1]+4);
                dp[i]=min(dp[i],dp[i-3]+cost[i-1]+9);
            }else if(i==2){
                dp[i]=min(dp[i],dp[i-1]+cost[i-1]+1);
                dp[i]=min(dp[i],dp[i-2]+cost[i-1]+4);
            }else if(i==1){
                dp[i]=min(dp[i],dp[i-1]+cost[i-1]+1);
            }
        }
        return dp[n];
    }
};