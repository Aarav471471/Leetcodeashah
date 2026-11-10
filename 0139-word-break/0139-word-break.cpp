class Solution {
public:
    vector<int>dp;
    int check(int i,string &s, vector<string>&wordDict){
        int n=s.size();
        if(i>=n){
            return 1;
        }
        if(dp[i]!=-1){return dp[i];}
        if((find(wordDict.begin(),wordDict.end(),s)!=wordDict.end())){
            return 1;
        }
        for(int j=1;j<=n;j++){
            if((find(wordDict.begin(),wordDict.end(),s.substr(i,j))!=wordDict.end()) && check(i+j,s,wordDict)){
                return dp[i]=1;
            }
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        dp.assign(n,-1);
        return check(0,s,wordDict);
    }
};