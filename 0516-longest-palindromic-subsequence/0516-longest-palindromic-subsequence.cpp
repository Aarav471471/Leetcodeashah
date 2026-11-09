class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int l=1;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=i+l-1;
                if(i==j){
                    dp[i][j]=1;
                }else if(s[i]==s[j]){
                        dp[i][j]=2+dp[i+1][j-1];
                    }else{
                        dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                    }
                
            }
        }
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         ans=max(dp[i][j],ans);
        //     }
        // }
        return dp[0][n-1];
    }
};