class Solution {
public:
typedef  long long ll;
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector< unsigned int>>dp(n+1,vector< unsigned int>(m+1,0));
        for(ll i=0; i<=n; i++){
            dp[i][m]=1;
        }
        for(ll i=n-1; i>=0; i--){
            for(ll j=m-1; j>=0; j--){
                if(s[i]==t[j]){
                    dp[i][j] = dp[i+1][j+1]+dp[i+1][j];
                }
                else dp[i][j]= dp[i+1][j];

            }
        }
        return dp[0][0];
        
    }
};