class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        int ans=0;
        string t="";
        for(int l=1;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=i+l-1;
                if(i==j){
                    dp[i][i]=true;
                }else if(i+1==j){
                    if(s[i]==s[j]){
                        dp[i][j]=true;
                    }
                }else{
                    if(s[i]==s[j] && dp[i+1][j-1]){
                        dp[i][j]=true;
                    }
                }
                if(dp[i][j]){
                    if(l>ans){
                        ans=l;
                        // cout<<i<<" "<<j<<endl;
                        t=s.substr(i,l);
                    }
                }
            }
        }   
        // cout<<ans<<endl;
        return t;
    }
};