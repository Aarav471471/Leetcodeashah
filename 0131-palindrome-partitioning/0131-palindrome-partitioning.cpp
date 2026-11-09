class Solution {
public:

    void parts(int i,vector<vector<bool>>&dp,string &s,vector<vector<string>>&ans,vector<string>&part){
        if(i>=s.size()){
            ans.push_back(part);
            // part.clear();
            return;
        }
        for(int j=i;j<s.size();j++){
            if(dp[i][j]){
                part.push_back(s.substr(i,j-i+1));
                parts(j+1,dp,s,ans,part);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>>ans;
        vector<vector<bool>>dp(n,vector<bool>(n,false));
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
            }
        }
        vector<string>part;
        parts(0,dp,s,ans,part);

        return ans;
    }
};