class Solution {
public:
    vector<vector<int>>dp;
    int check(int i,int j,string &s){
        if(i>j){return 1;}
        if(dp[i][j]!=-1){return dp[i][j];}
        if(s[i]==s[j]){
            return dp[i][j]=check(i+1,j-1,s);
        }
        return dp[i][j]=0;
    }
    int countSubstrings(string s) {
        int cnt=0;
        dp.assign(s.size(),vector<int>(s.size(),-1));
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(check(i,j,s)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};