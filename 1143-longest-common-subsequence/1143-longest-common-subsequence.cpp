class Solution {
public:
    vector<vector<int>>dp;
    int lcs(int i,int j,string &text1,string &text2){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){return dp[i][j];}
        int ans=0;
        if(text1[i]==text2[j]){
            ans=lcs(i-1,j-1,text1,text2)+1;
        }else{
            ans=max({lcs(i-1,j,text1,text2),lcs(i,j-1,text1,text2)});
        }
        return dp[i][j]=ans;

    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        dp.assign(n+1,vector<int>(m+1,-1));
        return lcs(n-1,m-1,text1,text2);
    }
};