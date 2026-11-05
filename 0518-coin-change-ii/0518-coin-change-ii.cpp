class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<unsigned long long>>dp(n+1,vector<unsigned long long>(amount+1,0));
        dp[0][0]=1;
        // if(coins[0]<=amount){dp}
        for(int i=0;i<=amount;i+=coins[0]){
            dp[0][i]=1;
        }

        for(int k=1;k<n;k++){
            int x=coins[k];
            for(int i=amount;i>=0;i--){

                for(int j=(i/x)*x;j>=0;j-=x){
                    dp[k][i]+=dp[k-1][i-j];
                }
            }
        }
        return dp[n-1][amount];
    }
};