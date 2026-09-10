class Solution {
public:
    vector<vector<int>>dp;
    int len(int i,int j,string &text1,string &text2){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){return dp[i][j];}
        int ans=0;
        if(text1[i]==text2[j]){
            ans=max(ans,1+len(i-1,j-1,text1,text2));
        }else{
            ans=max({ans,len(i-1,j,text1,text2),len(i,j-1,text1,text2)});
        }

        return dp[i][j]=ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        dp.assign(text1.size()+1,vector<int>(text2.size()+1,-1));
        return len(text1.size()-1,text2.size()-1,text1,text2);

    }
};