class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
         int n=text1.size();
               int m=text2.size();
               string t="";
               vector<vector<int>>dp(n,vector<int>(m,0));
               // if(text1[0]==text2[0]){dp[0][0]++;}
               for(int i=0;i<n;i++){
                   for(int j=0;j<m;j++){
                       if(text1[i]==text2[j]){
                           dp[i][j]=1;
                           if(i>0 && j>0){
                               dp[i][j]+=(dp[i-1][j-1]);
                            //    t+=text1[i];
                           }
                       }else{
                           if(i>0 && j>0){
                               dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                           }else if(i==0 && j>0){
                               dp[i][j]=max(dp[i][j],dp[i][j-1]);
                           }else if(i>0 && j==0){
                               dp[i][j]=max(dp[i][j],dp[i-1][j]);
                           }
                       }   
                   }
               }
                int i=n-1;
                int j=m-1;
                while(i>=0 && j>=0){

                    if(text1[i]==text2[j]){
                        t+=text1[i];
                        i--;
                        j--;
                    }
                    else if(i>0 && (j==0 || dp[i-1][j]>=dp[i][j-1])){
                        t+=text1[i];
                        i--;
                    }
                    else{
                        t+=text2[j];
                        j--;
                    }
                }

                while(i>=0){
                    t+=text1[i];
                    i--;
                }

                while(j>=0){
                    t+=text2[j];
                    j--;
                }

                reverse(t.begin(),t.end());
                return t;
    }
};