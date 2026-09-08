class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size=strs.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));

        for(auto x:strs){
            int z=0;
            int o=0;
            for(auto c:x){
                if(c=='0'){z++;}
                if(c=='1'){o++;}
            }

            for(int i=m;i>=z;i--){
                for(int j=n;j>=o;j--){
                    dp[i][j]=max(dp[i][j],dp[i-z][j-o]+1);
                }
            }
        }
        return dp[m][n];
    }
};